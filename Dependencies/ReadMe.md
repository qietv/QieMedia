# QieMedia Dependencies for OpenHarmony

Prebuilt binaries for QieMedia dependencies

## Build

```
vcpkg "--overlay-triplets=..\vcpkg-ohos-overlay\triplets" "--overlay-ports=..\vcpkg-ohos-overlay\ports" install c-ares:arm64-ohos-static curl:arm64-ohos-static openssl:arm64-ohos-static ffmpeg-4:arm64-ohos-static
vcpkg "--overlay-triplets=..\vcpkg-ohos-overlay\triplets" "--overlay-ports=..\vcpkg-ohos-overlay\ports" install c-ares:x64-ohos-static curl:x64-ohos-static openssl:x64-ohos-static ffmpeg-4:x64-ohos-static
```

Suggested to use "llvm-strip --strip-debug *.a" to reduce the static library
binary size.
