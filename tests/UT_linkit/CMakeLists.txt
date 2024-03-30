add_executable(UT_linkit
  signalTests.cpp
)

target_link_libraries(UT_linkit
  PRIVATE
    gtest_main
    linkit
)

add_test(NAME UT_linkit COMMAND UT_linkit)
