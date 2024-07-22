cmake_minimum_required(VERSION 3.10)
project(rename LANGUAGES CXX)
set(CMAKE_SUPPRESS_REGENERATION true)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# so that gha works f t m
set(CMAKE_SYSTEM_NAME Windows)
set(TOOLCHAIN_PREFIX x86)
set(CMAKE_GENERATOR_PLATFORM Win32)


add_compile_definitions( WIN32_LEAN_AND_MEAN   NOMINMAX    UNICODE    _UNICODE)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

if(MSVC)
    add_compile_options("/source-charset:utf-8" "/execution-charset:utf-8" "/GF")
    set(CMAKE_GENERATOR_PLATFORM x86)
    set(CMAKE_GENERATOR_TOOLSET "host=x86")
    set(CMAKE_VS_PLATFORM_NAME "x86")
else()
    add_compile_options("-finput-charset=UTF-8" "-fexec-charset=UTF-8" "-m32")
endif()

add_library(${PROJECT_NAME} SHARED main.cpp)
