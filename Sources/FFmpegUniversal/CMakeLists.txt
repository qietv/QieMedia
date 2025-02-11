cmake_minimum_required(VERSION 3.10.2)

project(FFmpegUniversal)

if (NOT (CMAKE_SYSTEM_NAME STREQUAL "OHOS"))
    message(
        FATAL_ERROR 
        "[FFmpegUniversal] Unsupported Platform: ${CMAKE_SYSTEM_NAME}"
    )
endif ()

if (OHOS_ARCH STREQUAL arm64-v8a)
    set(
        QIEMEDIA_DEPENDENCIES_HOME
        "${CMAKE_CURRENT_LIST_DIR}/../../Dependencies/arm64-ohos"
    )
elseif (OHOS_ARCH STREQUAL x86_64)
    set(
        QIEMEDIA_DEPENDENCIES_HOME
        "${CMAKE_CURRENT_LIST_DIR}/../../Dependencies/x64-ohos"
    )
endif ()

add_library(avcodec STATIC IMPORTED)
set_target_properties(
    avcodec 
    PROPERTIES 
    IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libavcodec.a
)

add_library(avdevice STATIC IMPORTED)
set_target_properties(
    avdevice 
    PROPERTIES 
    IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libavdevice.a
)

add_library(avfilter STATIC IMPORTED)
set_target_properties(
    avfilter 
    PROPERTIES 
    IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libavfilter.a
)

add_library(avformat STATIC IMPORTED)
set_target_properties(
    avformat 
    PROPERTIES 
    IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libavformat.a
)

add_library(avutil STATIC IMPORTED)
set_target_properties(
    avutil 
    PROPERTIES 
    IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libavutil.a
)

add_library(swresample STATIC IMPORTED)
set_target_properties(
    swresample 
    PROPERTIES 
    IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libswresample.a
)

add_library(swscale STATIC IMPORTED)
set_target_properties(
    swscale 
    PROPERTIES 
    IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libswscale.a
)

add_library(
    FFmpegUniversal 
    SHARED
    FFmpegUniversal.c
)

target_link_libraries(
    FFmpegUniversal
    PRIVATE
    -Wl,-Bsymbolic
    -Wl,--whole-archive
    avcodec
    avdevice
    avfilter
    avformat
    avutil
    swresample
    swscale
    -Wl,--no-whole-archive
)