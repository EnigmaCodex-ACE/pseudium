cmake_minimum_required (VERSION 3.6)
project(reimi)

add_executable(reimi reimi.cpp)

add_subdirectory(deps/sleepy-discord)
target_link_libraries(reimi sleepy-discord)