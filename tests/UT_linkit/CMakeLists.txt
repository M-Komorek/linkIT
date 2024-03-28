add_executable(UT_linkit
  signalTests.cpp
)

target_link_libraries(UT_linkit
  PRIVATE
    gtest_main
    linkit
)

target_include_directories(UT_linkit
  PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
)

add_test(NAME UT_linkit COMMAND UT_linkit)
