#include "RedFFUtil.h"
#include "RedLog.h"
#include "RedSourceCommon.h"
REDSOURCE_NS_BEGIN
int64_t get_bit_rate(AVCodecParameters *codecpar) {
  int64_t bit_rate;
  int bits_per_sample;

  switch (codecpar->codec_type) {
  case AVMEDIA_TYPE_VIDEO:
  case AVMEDIA_TYPE_DATA:
  case AVMEDIA_TYPE_SUBTITLE:
  case AVMEDIA_TYPE_ATTACHMENT:
    bit_rate = codecpar->bit_rate;
    break;
  case AVMEDIA_TYPE_AUDIO:
    bits_per_sample = av_get_bits_per_sample(codecpar->codec_id);
    bit_rate = bits_per_sample ? codecpar->sample_rate * codecpar->ch_layout.nb_channels *
                                     bits_per_sample
                               : codecpar->bit_rate;
    break;
  default:
    bit_rate = 0;
    break;
  }
  return bit_rate;
}

double get_rotation(AVStream *st) {
  AVDictionaryEntry *rotate_tag = av_dict_get(st->metadata, "rotate", NULL, 0);
  uint8_t *displaymatrix =
      av_stream_get_side_data(st, AV_PKT_DATA_DISPLAYMATRIX, NULL);
  double theta = 0;

  if (rotate_tag && *rotate_tag->value && strcmp(rotate_tag->value, "0")) {
    char *tail;
    theta = av_strtod(rotate_tag->value, &tail);
    if (*tail)
      theta = 0;
  }
  if (displaymatrix && !theta)
    theta =
        -av_display_rotation_get(reinterpret_cast<int32_t *>(displaymatrix));

  theta -= 360 * floor(theta / 360 + 0.9 / 360);

  if (fabs(theta - 90 * round(theta / 90)) > 2)
    AV_LOGW(
        SOURCE_LOG_TAG,
        "Odd rotation angle.\n"
        "If you want to help, upload a sample "
        "of this file to ftp://upload.ffmpeg.org/incoming/ "
        "and contact the ffmpeg-devel mailing list. (ffmpeg-devel@ffmpeg.org)");

  return theta;
}

AVDictionary **setup_find_stream_info_opts(AVFormatContext *s,
                                           AVDictionary *codec_opts) {
  int i;
  AVDictionary **opts;

  if (!s->nb_streams)
    return NULL;
  opts =
      static_cast<AVDictionary **>(av_mallocz(s->nb_streams * sizeof(*opts)));
  if (!opts) {
    av_log(NULL, AV_LOG_ERROR, "Could not alloc memory for stream options.\n");
    return NULL;
  }
  for (i = 0; i < s->nb_streams; i++)
    opts[i] = filter_codec_opts(codec_opts, s->streams[i]->codecpar->codec_id,
                                s, s->streams[i], NULL);
  return opts;
}

static int check_stream_specifier(AVFormatContext *s, AVStream *st,
                                  const char *spec) {
  int ret = avformat_match_stream_specifier(s, st, spec);
  if (ret < 0)
    av_log(s, AV_LOG_ERROR, "Invalid stream specifier: %s.\n", spec);
  return ret;
}

AVDictionary *filter_codec_opts(AVDictionary *opts, enum AVCodecID codec_id,
                                AVFormatContext *s, AVStream *st,
                                AVCodec *codec) {
  AVDictionary *ret = NULL;
  AVDictionaryEntry *t = NULL;
  int flags =
      s->oformat ? AV_OPT_FLAG_ENCODING_PARAM : AV_OPT_FLAG_DECODING_PARAM;
  char prefix = 0;
  const AVClass *cc = avcodec_get_class();

  if (!codec)
    codec = const_cast<AVCodec *>(s->oformat ? avcodec_find_encoder(codec_id)
                                             : avcodec_find_decoder(codec_id));

  switch (st->codecpar->codec_type) {
  case AVMEDIA_TYPE_VIDEO:
    prefix = 'v';
    flags |= AV_OPT_FLAG_VIDEO_PARAM;
    break;
  case AVMEDIA_TYPE_AUDIO:
    prefix = 'a';
    flags |= AV_OPT_FLAG_AUDIO_PARAM;
    break;
  case AVMEDIA_TYPE_SUBTITLE:
    prefix = 's';
    flags |= AV_OPT_FLAG_SUBTITLE_PARAM;
    break;
  default:
    break;
  }

  while ((t = av_dict_get(opts, "", t, AV_DICT_IGNORE_SUFFIX))) {
    char *p = strchr(t->key, ':');

    /* check stream specification in opt name */
    if (p) {
      switch (check_stream_specifier(s, st, p + 1)) {
      case 1:
        *p = 0;
        break;
      case 0:
        continue;
      default:
        return NULL;
      }
    }

    if (av_opt_find(&cc, t->key, NULL, flags, AV_OPT_SEARCH_FAKE_OBJ) ||
        (codec && codec->priv_class &&
         av_opt_find(&codec->priv_class, t->key, NULL, flags,
                     AV_OPT_SEARCH_FAKE_OBJ)))
      av_dict_set(&ret, t->key, t->value, 0);
    else if (t->key[0] == prefix &&
             av_opt_find(&cc, t->key + 1, NULL, flags, AV_OPT_SEARCH_FAKE_OBJ))
      av_dict_set(&ret, t->key + 1, t->value, 0);

    if (p) {
      *p = ':';
    }
  }
  return ret;
}
REDSOURCE_NS_END
