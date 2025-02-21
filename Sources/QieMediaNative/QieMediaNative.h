/*
 * PROJECT:   QieMedia
 * FILE:      QieMediaNative.h
 * PURPOSE:   Definition for QieMediaNative library for OpenHarmony
 *
 * LICENSE:   See License.md file in the project root
 *
 * MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
 */

#ifndef QIEMEDIA_NATIVE
#define QIEMEDIA_NATIVE

#include <cstdint>
#include <string>

namespace QieMedia::Native
{
    enum class MediaPlaybackState : std::uint8_t
    {
        None = 0,
        Opening = 1,
        Buffering = 2,
        Playing = 3,
        Paused = 4,
    };

    struct MediaPlaybackInformation
    {
        std::string SessionId;
        std::string SurfaceId;
        std::string SourceUri;
        std::int64_t SourceFileDescriptor;
        std::string AudioCodecType;
        std::string VideoCodecType;
        std::uint32_t NaturalVideoWidth;
        std::uint32_t NaturalVideoHeight;
        std::uint64_t NaturalDuration;
        std::uint64_t Position;
        float PlaybackRate; // OH_AudioRenderer_GetSpeed
        float Volume; // OH_AudioRenderer_GetVolume
        MediaPlaybackState PlaybackState;
        bool IsLooping;
        bool IsMuted;
    };
}

#endif // !QIEMEDIA_NATIVE
