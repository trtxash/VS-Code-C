project(process)

add_library(${PROJECT_NAME}
    SHARED
    process.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${Study_Dir}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    study
)