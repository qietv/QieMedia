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
// PlaybackState { get; } which is QieMedia::Native::MediaPlaybackState
// IsLooping { get; set; }
// NaturalDuration { get; } is the actual duration of the media without applying the PlaybackRate
// IsMuted { get; set; }
// Information { get; } // JSON string
//

#include <cstddef>

#include <napi/native_api.h>

namespace
{
    static const napi_property_descriptor g_RegisteredProperties[] =
    {
        {
            .utf8name = "CreatePlaybackSession",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "ClosePlaybackSession",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "QueryPlaybackSession",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "SetFileSource",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "SetUriSource",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "SetSurface",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "Load",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "Reset",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "Pause",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "Play",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "Stop",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "SetPosition",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "SetPlaybackRate",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "SetVolume",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "SetLooping",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "SetMuted",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        },
        {
            .utf8name = "GetInformation",
            .name = nullptr,
            .method = nullptr, // TODO
            .getter = nullptr,
            .setter = nullptr,
            .value = nullptr,
            .attributes = napi_default,
            .data = nullptr,
        }
    };

    static const std::size_t g_RegisteredPropertiesCount =
        sizeof(g_RegisteredProperties) / sizeof(*g_RegisteredProperties);

    static napi_value QieMediaNativeModuleRegisterHandler(
        napi_env env,
        napi_value exports)
    {
        ::napi_define_properties(
            env,
            exports,
            g_RegisteredPropertiesCount,
            g_RegisteredProperties);
        return exports;
    }

    static napi_module g_QieMediaNativeModule =
    {
        .nm_version = 1,
        .nm_flags = 0,
        .nm_filename = nullptr,
        .nm_register_func = ::QieMediaNativeModuleRegisterHandler,
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
