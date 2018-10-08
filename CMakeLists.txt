cmake_minimum_required (VERSION 2.6)
project(Engine)

add_executable(game
  src/sandbox/main.cpp

)

add_library(myengine
  src/myengine/Component.cpp
  src/myengine/Component.h
  src/myengine/Core.cpp
  src/myengine/Core.h
  src/myengine/Entity.cpp
  src/myengine/Entity.h
  src/myengine/Environment.cpp
  src/myengine/Environment.h
  src/myengine/Keyboard.cpp
  src/myengine/Keyboard.h
)