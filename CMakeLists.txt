cmake_minimum_required (VERSION 2.6)
project(Engine)

include_directories(
  src
  src/myengine
  contrib
)

if(MSVC)
  include_directories(
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
  )
else()
  include_directories(
    /usr/X11R6/include
    /usr/local/include
  )

  link_directories(
    /usr/X11R6/lib
    /usr/local/lib
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

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
  src/myengine/ShaderProgram.cpp
  src/myengine/ShaderProgram.h  
  src/myengine/Transform.cpp
  src/myengine/Transform.h
  src/myengine/VertexArray.cpp
  src/myengine/VertexArray.h
  src/myengine/VertexBuffer.cpp
  src/myengine/VertexBuffer.h

)

if(MSVC)
  target_link_libraries(myengine
    SDL2 glew32 opengl32
  )
else()
  target_link_libraries(myengine
    SDL2 GLU GLEW GL
  )
endif()

add_executable(sandbox
  src/sandbox/main.cpp
  src/sandbox/TestScreen.cpp
  src/sandbox/TestScreen.h
)

target_link_libraries(sandbox myengine)

if(MSVC)
  add_custom_command(TARGET sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:sandbox>"
  )

  add_custom_command(TARGET sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:sandbox>"
  )
endif()
