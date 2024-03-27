add_library(linkit SHARED signal.cpp)
target_include_directories(linkit PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
