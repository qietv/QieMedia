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

#include <map>
#include <string>
#include <vector>

namespace Mile::NodeInterop
{
    napi_status GetCallbackArguments(
        napi_env EnvironmentObject,
        napi_callback_info CallbackInformationObject,
        std::vector<napi_value>& Arguments)
    {
        Arguments.clear();
        std::size_t ArgumentsCount = 0;
        napi_status Status = ::napi_get_cb_info(
            EnvironmentObject,
            CallbackInformationObject,
            &ArgumentsCount,
            nullptr,
            nullptr,
            nullptr);
        if (Status == napi_ok)
        {
            Arguments.resize(ArgumentsCount);
            Status = ::napi_get_cb_info(
                EnvironmentObject,
                CallbackInformationObject,
                &ArgumentsCount,
                Arguments.data(),
                nullptr,
                nullptr);
        }
        return Status;
    }

    std::string ToString(
        napi_env env,
        napi_value value)
    {
        std::size_t Length = 0;
        if (napi_ok == ::napi_get_value_string_utf8(
            env,
            value,
            nullptr,
            0,
            &Length))
        {
            std::string Result(Length, '\0');
            if (napi_ok == ::napi_get_value_string_utf8(
                env,
                value,
                &Result[0],
                Length,
                &Length))
            {
                return Result;
            }
        }
        
        return std::string();
    }
}

namespace
{
    using MediaPlaybackSession = QieMedia::Native::MediaPlaybackSession;
    static std::map<std::string, MediaPlaybackSession> g_PlaybackSessions;

    napi_value CreatePlaybackSession(
        napi_env EnvironmentObject,
        napi_callback_info CallbackInformationObject)
    {
        std::vector<napi_value> Arguments;
        if (napi_ok != Mile::NodeInterop::GetCallbackArguments(
            EnvironmentObject,
            CallbackInformationObject,
            Arguments))
        {
            // TODO
            return nullptr;
        }

        // TODO
        return nullptr;
    }

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
        napi_env EnvironmentObject,
        napi_value ExportsObject)
    {
        ::napi_define_properties(
            EnvironmentObject,
            ExportsObject,
            g_RegisteredPropertiesCount,
            g_RegisteredProperties);
        return ExportsObject;
    }

    static napi_module g_QieMediaNativeModule =
    {
        .nm_version = 1,
        .nm_flags = 0,
        .nm_filename = nullptr,
        .nm_register_func = ::QieMediaNativeModuleRegisterHandler,
        .nm_modname = "QieMediaNative",
        .nm_priv = nullptr,
        .reserved = { nullptr },
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
