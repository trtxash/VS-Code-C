project(main_task)

add_subdirectory(process)
add_subdirectory(user)
add_subdirectory(mystl)

add_executable(${PROJECT_NAME} main_task.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main") # 添加改名配置（将new_name替换为实际名称）

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${Process_Dir}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    process
)
