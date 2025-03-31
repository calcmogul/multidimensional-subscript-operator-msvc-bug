cmake_minimum_required(VERSION 3.21)

project(App LANGUAGES CXX)

add_executable(App main.cpp)
if(MSVC)
    target_compile_options(App PUBLIC /std:c++23preview)
else()
    target_compile_options(
        App
        PRIVATE -Wall -Wextra -Wno-unused-parameter -pedantic
    )
    target_compile_features(App PUBLIC cxx_std_23)
endif()
