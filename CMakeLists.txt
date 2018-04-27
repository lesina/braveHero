cmake_minimum_required(VERSION 3.6)
project(braveHero)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lX11 -lXxf86vm -lGL -lpthread -lXrandr -lXi -lglfw3 -Wl,--no-as-needed -ldl -lXinerama -lXcursor")

set(SOURCE_FILES main.cpp glad.c Code/SDK/FX/Shader.cpp Code/SDK/FX/Shader.h Code/SDK/Game/GameStartup.cpp Code/SDK/Game/GameStartup.h Code/logging.cpp Code/logging.h Code/SDK/Game/Settings.cpp Code/SDK/Game/Settings.h Code/SDK/Game/Objects/GameObject.cpp Code/SDK/Game/Objects/GameObject.h Code/stb_image.cpp Code/stb_image.h Code/SDK/Game/Objects/PhysObject.cpp Code/SDK/Game/Objects/PhysObject.h Code/SDK/Game/Objects/GraphObject.cpp Code/SDK/Game/Objects/GraphObject.h)
add_executable(braveHero ${SOURCE_FILES})
target_link_libraries(braveHero glfw3 ${OPENGL_LIBRARIES} X11 Xxf86vm pthread Xrandr)