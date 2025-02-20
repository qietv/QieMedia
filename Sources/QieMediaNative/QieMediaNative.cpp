/*
 * PROJECT:   QieMedia
 * FILE:      QieMediaNative.cpp
 * PURPOSE:   Implementation for QieMediaNative library for OpenHarmony
 *
 * LICENSE:   See License.md file in the project root
 *
 * MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
 */

#include "QieMediaNative.h"

extern "C" void QieMediaNativeEmptySymbol()
{
    // Do Nothing
}

//
// CreatePlaybackSession(std::string SessionId)
// ClosePlaybackSession(std::string SessionId)
// QueryPlaybackSession() // JSON string
//
// PlaybackSession
//
// SetFileSource(int FileDescriptor)
// SetUriSource(std::string Uri)
// SetSurface(int SurfaceId)
//
// Load()
// Reset()
// 
// Pause()
// Play()
// Stop() is Pause() and Position = 0
//
// Position { get; set; }
// PlaybackRate { get; set; }
// Volume { get; set; }
// PlaybackState { get; } enum MediaPlaybackState { None, Opening, Buffering, Playing, Paused, Stopped }
// IsLooping { get; set; }
// NaturalDuration { get; } is the actual duration of the media without applying the PlaybackRate
// IsMuted { get; set; }
// Information { get; } // JSON string
//

#include <napi/native_api.h>

namespace
{
    static napi_module g_QieMediaNativeModule =
    {
        .nm_version = 1,
        .nm_flags = 0,
        .nm_filename = nullptr,
        .nm_register_func = nullptr, // TODO
        .nm_modname = "QieMediaNative",
        .nm_priv = nullptr,
        .reserved = { nullptr, nullptr, nullptr, nullptr },
    };
}

#ifndef EXTERN_C
#define EXTERN_C extern "C"
#endif // !EXTERN_C

#ifndef ATTRIBUTE_CONSTRUCTOR
#define ATTRIBUTE_CONSTRUCTOR __attribute__((constructor))
#endif // !ATTRIBUTE_CONSTRUCTOR

EXTERN_C ATTRIBUTE_CONSTRUCTOR void QieMediaNativeRegisterModule()
{
    ::napi_module_register(&g_QieMediaNativeModule);
}
