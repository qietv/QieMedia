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
  QieMedia 
  SHARED
  "QieMedia.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET QieMedia PROPERTY CXX_STANDARD 17)
endif()

target_link_libraries(
  QieMedia
  c)
