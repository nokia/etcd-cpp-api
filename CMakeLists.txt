cmake_minimum_required (VERSION 3.1.3 FATAL_ERROR)
project (etcd-cpp-api)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(CPPREST)
find_package(CATCH)
find_package(Boost REQUIRED COMPONENTS system thread locale random)

set(WITH_TEST TRUE CACHE BOOL "Enable testing.")
if(WITH_TEST AND NOT CATCH_FOUND)
  message(STATUS "Libraries not found: catch. Disabling testing.")
endif()

set (etcd-cpp-api_VERSION_MAJOR 0)
set (etcd-cpp-api_VERSION_MINOR 1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_subdirectory(src)

if (WITH_TEST AND CATCH_FOUND)
  enable_testing()
  add_subdirectory(tst)
endif()
