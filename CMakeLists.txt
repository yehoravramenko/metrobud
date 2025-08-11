cmake_minimum_required(VERSION 3.15)
project(Metrobud)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB sources 
    src/main.cpp) 

set(includes thirdparty/RGFW)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/metrobud)

add_executable(metrobud ${sources})

set_property(TARGET metrobud PROPERTY CXX_STANDARD 23)
set_property(TARGET metrobud PROPERTY COMPILE_WARNING_AS_ERROR ON)

target_include_directories(metrobud PRIVATE ${includes})

#add_custom_command(TARGET winyl POST_BUILD
#    COMMAND copy compile_commands.json ..
#)
