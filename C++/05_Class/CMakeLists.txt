cmake_minimum_required(VERSION 3.28.3) # Minimum version of CMake required
project(
    Template # Name of the project
    VERSION 0.0.1 # Version number of the project
    DESCRIPTION "A template project for C++" # Short description of the project
    HOMEPAGE_URL "https://github.com/trtxash/VS-Code-C" # Homepage URL of the project
    LANGUAGES CXX # Languages used in the project
)

set(CMAKE_CXX_STANDARD 11) # C++ standard to use

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin) # Set the output directory for the executable files
set(Process_Dir ${CMAKE_SOURCE_DIR}/src/Process) # Set the directory containing the source files for the Process library
set(Study_Dir ${CMAKE_SOURCE_DIR}/src/Study) # Set the directory containing the source files for the Study library

add_subdirectory(src) # Add subdirectory containing source files