cmake_minimum_required(VERSION 3.10.2)

project(redsource)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wno-deprecated")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG ")

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(EXTRA_DIR "${ROOT_DIR}/../extra")
set(REDBASE_DIR "${ROOT_DIR}/../redbase")

if (OHOS_ARCH STREQUAL arm64-v8a)
    set(
        QIEMEDIA_DEPENDENCIES_HOME
        "${ROOT_DIR}/../../../../Dependencies/arm64-ohos"
    )
elseif (OHOS_ARCH STREQUAL x86_64)
    set(
        QIEMEDIA_DEPENDENCIES_HOME
        "${ROOT_DIR}/../../../../Dependencies/x64-ohos"
    )
endif ()

if(CMAKE_SYSTEM_NAME STREQUAL "Android")
  set(TARGET_PLATFORM android)
  set(CMAKE_SYSTEM_VERSION 21)
  set(CMAKE_ANDROID_NDK $ENV{ANDROID_NDK})
  set(EXTRA_FFMPEG_DIR
      "${EXTRA_DIR}/ffmpeg/${TARGET_PLATFORM}/${CMAKE_ANDROID_ARCH_ABI}"
  )
elseif(CMAKE_SYSTEM_NAME STREQUAL "OHOS")
  add_definitions(-D__HARMONY__)
  set(TARGET_PLATFORM harmony)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-command-line-argument"
  )
  set(EXTRA_FFMPEG_DIR "${EXTRA_DIR}/ffmpeg/${TARGET_PLATFORM}/${OHOS_ARCH}")
else()
  message(
    FATAL_ERROR "This CMake script does not support ${CMAKE_SYSTEM_NAME}!"
  )
endif()

set(EXTRA_REDBASE_DIR "${REDBASE_DIR}")

include_directories(
  "${QIEMEDIA_DEPENDENCIES_HOME}/include"
  "${EXTRA_REDBASE_DIR}/include"
  ${CMAKE_CURRENT_SOURCE_DIR}
)

set(SRC_LIST
    RedFFExtractor.cc
    RedSource.cc
    RedFFUtil.cc
    RedExtractorFactory.cc
)

add_library(redsource SHARED ${SRC_LIST})

if(CMAKE_SYSTEM_NAME STREQUAL "Android")
  find_library(log-lib log)
  target_link_libraries(
    redsource
    ${log-lib}
    ffmpeg
    redbase
  )
elseif(CMAKE_SYSTEM_NAME STREQUAL "OHOS")
  find_library(log-lib hilog_ndk.z)
  target_link_libraries(
    redsource
    ${log-lib}
    FFmpegUniversal
    redbase
  )
else()
  message(
    FATAL_ERROR "This CMake script does not support ${CMAKE_SYSTEM_NAME}!"
  )
endif()
