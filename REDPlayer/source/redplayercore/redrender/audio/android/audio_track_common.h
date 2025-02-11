#if defined(__ANDROID__)
#pragma once
#include <cstdint>

#include "../../redrender_macro_definition.h"

NS_REDRENDER_AUDIO_BEGIN
constexpr int KAudioTrackPlaybackMaxSpeed = 2;

enum class AudioTrackStreamType {
  kStreamVoiceCall = 0,
  kStreamSystem = 1,
  kStreamRing = 2,
  kStreamMusic = 3,
  kStreamAlarm = 4,
  kStream_Notification = 5,
};

enum class AudioTrackFormat {
  kEncodingInvalid = 0,
  kEncodingDefault = 1,
  kEncodingPcm16Bit = 2,
  kEncodingPcm8Bit = 3,
  kEncodingPcmFloat = 4,
};

enum class AudioTrackMode {
  kModeStatic = 0,
  kModeStream = 1,
};

enum class AudioTrackChannelConfig {
  kChannelOutInvalid = 0x0,
  kChannelOutDefault = 0x1,    /* f-l */
  kChannelOutMono = 0x4,       /* f-l, f-r */
  kChannelOutStero = 0xc,      /* f-l, f-r, b-l, b-r */
  kChannelOutQuad = 0xcc,      /* f-l, f-r, b-l, b-r */
  kChannelOutSurround = 0x41c, /* f-l, f-r, f-c, b-c */
  kChannelOut5Point1 = 0xfc,   /* f-l, f-r, b-l, b-r, f-c, low */
  kChannelOut7Point1 = 0x3fc,  /* f-l, f-r, b-l, b-r, f-c, low, f-lc, f-rc */
  kChannelOutFrontLeft = 0x4,
  kChannelOutFrontRight = 0x8,
  kChannelOutBackLeft = 0x40,
  kChannelOutBackRight = 0x80,
  kChannelOutFrontCenter = 0x10,
  kChannelOutLowFrenquency = 0x20,
  kChannelOutFrontLeftOfCenter = 0x100,
  kChannelOutFrontRightOfCenter = 0x200,
  kChannelOutBackCenter = 0x400,
};

NS_REDRENDER_AUDIO_END
#endif
