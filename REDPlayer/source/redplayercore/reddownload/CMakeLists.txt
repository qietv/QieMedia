cmake_minimum_required(VERSION 3.10.2)

project(redplayer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wno-deprecated")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG ")

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(EXTRA_DIR "${ROOT_DIR}/../extra")
set(REDBASE_DIR "${ROOT_DIR}/../redbase")
set(JSON_DIR "${EXTRA_DIR}/nlohmann-json")

if(OHOS_ARCH STREQUAL arm64-v8a)
  set(QIEMEDIA_DEPENDENCIES_HOME "${ROOT_DIR}/../../../../Dependencies/arm64-ohos")
elseif(OHOS_ARCH STREQUAL x86_64)
  set(QIEMEDIA_DEPENDENCIES_HOME "${ROOT_DIR}/../../../../Dependencies/x64-ohos")
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Android")
  set(TARGET_PLATFORM android)
  set(CURL_DIR ${EXTRA_DIR}/curl/${TARGET_PLATFORM}/${ANDROID_ABI})
  set(CARES_DIR ${EXTRA_DIR}/cares/${TARGET_PLATFORM}/${ANDROID_ABI})
  set(OPENSSL_DIR ${EXTRA_DIR}/openssl/${TARGET_PLATFORM}/${ANDROID_ABI})
elseif(CMAKE_SYSTEM_NAME STREQUAL "OHOS")
  add_definitions(-D__HARMONY__)
  set(TARGET_PLATFORM harmony)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-command-line-argument")
else()
  message(
    FATAL_ERROR "This CMake script does not support ${CMAKE_SYSTEM_NAME}!"
  )
endif()

include_directories(
  ${QIEMEDIA_DEPENDENCIES_HOME}/include
  ${REDBASE_DIR}/include
  ${JSON_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

aux_source_directory(. SRC_LIST)
aux_source_directory(./dnscache DNS_SRC_LIST)
aux_source_directory(./utility UTILITY_SRC_LIST)
aux_source_directory(./wrapper WRAPPER_SRC_LIST)
list(
  APPEND
  SRC_LIST
  ${DNS_SRC_LIST}
  ${WRAPPER_SRC_LIST}
  ${UTILITY_SRC_LIST}
)

add_library(curl STATIC IMPORTED)
set_target_properties(
  curl PROPERTIES IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libcurl.a
)
add_library(cares STATIC IMPORTED)
set_target_properties(
  cares PROPERTIES IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libcares.a
)
add_library(crypto STATIC IMPORTED)
set_target_properties(
  crypto PROPERTIES IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libcrypto.a
)
add_library(ssl STATIC IMPORTED)
set_target_properties(
  ssl PROPERTIES IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libssl.a
)
add_library(z STATIC IMPORTED)
set_target_properties(
  z PROPERTIES IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libz.a
)

if(CMAKE_SYSTEM_NAME STREQUAL "Android")
  add_library(reddownload SHARED ${SRC_LIST})
  find_library(log-lib log)
elseif(CMAKE_SYSTEM_NAME STREQUAL "OHOS")
  add_library(reddownload SHARED ${SRC_LIST})
  find_library(log-lib hilog_ndk.z)
endif()

target_link_libraries(
  reddownload
  ${log-lib}
  z
  curl
  cares
  ssl
  crypto
  redbase
)
