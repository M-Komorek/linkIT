add_library(linkIt SHARED signal.cpp)
target_include_directories(linkIt PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
