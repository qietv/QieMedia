﻿# QieMedia Dependencies for OpenHarmony

Prebuilt binaries for QieMedia dependencies with [vcpkg-ohos-overlay].

[vcpkg-ohos-overlay]: https://github.com/qietv/vcpkg-ohos-overlay

## Build

```
vcpkg "--overlay-triplets=..\vcpkg-ohos-overlay\triplets" "--overlay-ports=..\vcpkg-ohos-overlay\ports" install c-ares:arm64-ohos-static curl:arm64-ohos-static openssl:arm64-ohos-static ffmpeg-7p1-edge[openssl]:arm64-ohos-static
vcpkg "--overlay-triplets=..\vcpkg-ohos-overlay\triplets" "--overlay-ports=..\vcpkg-ohos-overlay\ports" install c-ares:x64-ohos-static curl:x64-ohos-static openssl:x64-ohos-static ffmpeg-7p1-edge[openssl]:x64-ohos-static
```

Suggested to use "llvm-strip --strip-debug *.a" to reduce the static library
binary size.
