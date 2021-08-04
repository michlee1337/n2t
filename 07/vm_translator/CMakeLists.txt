cmake_minimum_required(VERSION 3.20.5)
set (CMAKE_CXX_STANDARD 17)

project(vm_translator)

enable_testing()

## DEPENDENCIES

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

## SOURCES
add_subdirectory(src)
add_subdirectory(exe)
