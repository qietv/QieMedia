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
