## 
## PROJECT:   QieMedia
## FILE:      CMakeLists.txt
## PURPOSE:   The CMake project file
## 
## LICENSE:   See License.md file in the project root
## 
## MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
## 

add_library(
  QieMediaNative 
  SHARED
  "QieMediaNative.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(
    TARGET QieMediaNative
    PROPERTY CXX_STANDARD 17)
endif()

target_link_libraries(
  QieMediaNative
  c
  ace_napi.z
  hilog_ndk.z)
