project(main_task)

add_subdirectory(user)

add_executable(${PROJECT_NAME} main.c)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main") # 添加改名配置

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    user
)
