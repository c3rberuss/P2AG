cmake_minimum_required(VERSION 3.13)
project(Parcial)

set(CMAKE_CXX_STANDARD 14)

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS}) # incluir los directorios
link_directories(${GLUT_LIBRARY_DIRS}) # Linkeo de directorios
add_definitions(${GLUT_DEFINITIONS}) # Agregar las definiciones


find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

add_executable(Parcial main.cpp include/materials.h include/glibrary.h)

target_link_libraries(Parcial ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${CMAKE_SOURCE_DIR}/lib/libGL.a)