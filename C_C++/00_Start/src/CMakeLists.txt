project(main_task)

add_subdirectory(user)

add_executable(${PROJECT_NAME} main.c)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main") # 添加改名配置

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${Include_Dir}
    ${Include_Dir}/user
)

# target_link_libraries(${PROJECT_NAME}
# PUBLIC
# process
# )
