project(process)

add_library(${PROJECT_NAME}
    SHARED
    process.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${User_Dir}
    ${Temptest_Dir}

    # ${Third_Past_Dir}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    user
    temptest

    # third_past
)