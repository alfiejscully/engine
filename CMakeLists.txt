cmake_minimum_required (VERSION 2.6)
project(Engine)

add_executable(game
  src/sandbox/main.cpp

)

add_library(myengine
  src/myengine/Entity.cpp
)