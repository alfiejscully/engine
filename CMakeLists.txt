cmake_minimum_required (VERSION 2.6)
project(Engine)

add_executable(game
  src/sandbox/main.cpp
  src/sandbox/TestScreen.cpp
  src/sandbox/TestScreen.h
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
  src/myengine/Material.cpp
  src/myengine/Material.h
  src/myengine/MaterialAttribute.cpp
  src/myengine/MaterialAttribute.h
  src/myengine/MeshRenderer.cpp
  src/myengine/MeshRenderer.h
  src/myengine/Resources.cpp
  src/myengine/Resources.h
  src/myengine/Screen.cpp
  src/myengine/Screen.h
  src/myengine/Transform.cpp
  src/myengine/Transform.h

)