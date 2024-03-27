cmake_minimum_required(VERSION 3.25)
project(linkit)

include(cmake/CommonProperties.cmake)

set(BUILD_TESTS ON CACHE BOOL "Include tests to build process")

add_subdirectory(src)

if (BUILD_TESTS)
  include(CTest)
  add_subdirectory(tests)
endif()
