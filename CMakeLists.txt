cmake_minimum_required(VERSION 3.7)
project(RBTreeTemplate)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp RBTree.h Tests.cpp Tests.h)
add_executable(RBTreeTemplate ${SOURCE_FILES})