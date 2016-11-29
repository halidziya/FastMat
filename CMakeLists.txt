cmake_minimum_required(VERSION 2.6)
project(FastMat)

macro(use_cxx11)
    if (CMAKE_VERSION VERSION_LESS "3.1")
        if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
            set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
        endif ()
    else ()
        set (CMAKE_CXX_STANDARD 11)
    endif ()
endmacro(use_cxx11)


set(CMAKE_CXX_STANDARD 11)
use_cxx11()


ADD_LIBRARY( FastMat STATIC
    Buffer.cpp
    Buffer.h
    DebugUtils.h
    Dirichlet.cpp
    Dirichlet.h
    Distribution.cpp
    Distribution.h
    FastMat.h
    Global.cpp
    Global.h
    IWishart.cpp
    IWishart.h
    Matrix.cpp
    Matrix.h
    Normal.cpp
    Normal.h
    Readme.md
    Stut.cpp
    Stut.h
    ThreadPool.cpp
    ThreadPool.h
    util.cpp
    util.h
    Vector.cpp
    Vector.h
    Wishart.cpp
    Wishart.h)


TARGET_LINK_LIBRARIES( FastMat )
target_compile_features(FastMat PRIVATE cxx_range_for)