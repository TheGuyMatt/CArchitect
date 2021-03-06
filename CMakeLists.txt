cmake_minimum_required(VERSION 3.18.4)

project(CArchitect)

# Find Libraries
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")
find_package(SDL2 REQUIRED COMPONENTS main)
find_package(SDL2_image REQUIRED)

# Compile the Executable
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2main_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Load Headers
file(GLOB_RECURSE HDRS "${CMAKE_SOURCE_DIR}/src/*.h")
# Load Sources
file(GLOB_RECURSE SRCS "${CMAKE_SOURCE_DIR}/src/*.c")

add_executable(CArchitect ${HDRS} ${SRCS})

target_link_libraries(CArchitect ${SDL2_LIBS} ${SDL2_IMAGE_LIBRARIES}) 

# Copy SDL2 DLLs to output folder on Windows
# if(WIN32)
#   foreach(DLL ${SDL2_DLLS})
#     add_custom_command(TARGET CArchitect POST_BUILD COMMAND
#       ${CMAKE_COMMAND} -E copy_if_different ${DLL} $<TARGET_FILE_DIR:CArchitectLinux>)
#   endforeach()
# endif()
