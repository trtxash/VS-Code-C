project(user)

add_library(${PROJECT_NAME}
    STATIC
    mymath.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${Include_Dir}/user
)