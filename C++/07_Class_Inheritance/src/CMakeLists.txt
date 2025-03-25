project(main_task)

add_subdirectory(process)
add_subdirectory(user)
add_subdirectory(mystl)

add_executable(${PROJECT_NAME} main_task.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${Process_Dir}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    process
)
