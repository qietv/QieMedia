cmake_minimum_required(VERSION 3.10.2)

project(OpenSSLUniversal)

if (NOT (CMAKE_SYSTEM_NAME STREQUAL "OHOS"))
    message(
        FATAL_ERROR 
        "[OpenSSLUniversal] Unsupported Platform: ${CMAKE_SYSTEM_NAME}"
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

add_library(crypto STATIC IMPORTED)
set_target_properties(
    crypto 
    PROPERTIES 
    IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libcrypto.a
)

add_library(ssl STATIC IMPORTED)
set_target_properties(
    ssl 
    PROPERTIES 
    IMPORTED_LOCATION ${QIEMEDIA_DEPENDENCIES_HOME}/lib/libssl.a
)

add_library(
    OpenSSLUniversal 
    SHARED
    OpenSSLUniversal.c
)

target_link_libraries(
    OpenSSLUniversal
    PRIVATE
    -Wl,-Bsymbolic
    -Wl,--whole-archive
    crypto
    ssl
    -Wl,--no-whole-archive
)