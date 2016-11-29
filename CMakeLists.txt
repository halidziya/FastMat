cmake_minimum_required(VERSION 2.6)
project(FastMat)

set(CMAKE_CXX_STANDARD 11)



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

