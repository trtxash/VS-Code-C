cmake_minimum_required(VERSION 3.28.3) # Minimum version of CMake required
project(
    Template # Name of the project
    VERSION 0.0.1 # Version number of the project
    DESCRIPTION "A template project for C++" # Short description of the project
    HOMEPAGE_URL "https://github.com/trtxash/VS-Code-C" # Homepage URL of the project
    LANGUAGES CXX # Languages used in the project
)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON) # Enforce C standard
set(CMAKE_C_EXTENSIONS ON) # Enable C extensions
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(CXX C ASM)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin) # Set the output directory for the executable files
set(Include_Dir ${CMAKE_SOURCE_DIR}/inc)
set(User_Dir ${CMAKE_SOURCE_DIR}/src/user)
set(Third_Past_Dir ${CMAKE_SOURCE_DIR}/third_past)

add_subdirectory(src) # Add subdirectory containing source files
add_subdirectory(third_past)