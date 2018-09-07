cmake_minimum_required(VERSION 3.9.4)

set(PROJECT_NAME Lem-in)


#*------------------------------------*\
#    --  NAME PROJET  --
#*------------------------------------*/
project(${PROJECT_NAME} C)

#*------------------------------------*\
#    --  COMPILATEUR OPTION  --
#*------------------------------------*/
set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -og -g3")

#-fsanitize=memory-fsanitize-memory-track-origins=2 -fsanitize=address

add_executable(
        lem_in__run
        file/main.c
)

#*------------------------------------*\
#    --  PATH  --
#*------------------------------------*/
set(REPO "file/")

#*------------------------------------*\
#    -- LIB FT FILE --
#*------------------------------------*/
add_subdirectory(libft)

#*------------------------------------*\
#    --  PROJET FILE  --
#*------------------------------------*/
add_subdirectory(file)

#*------------------------------------*\
#    --  TEST FILE  --
#*------------------------------------*/
#file(GLOB sources06 "test/*.c")
#file(GLOB sources07 "includes/*.c")
#file(GLOB sources08 "includes/*.h")

#*------------------------------------*\
#    --  LINKING --
#*------------------------------------*/
target_link_libraries(lem_in__run lem_in__lib)
target_link_libraries(lem_in__run libft)


#*------------------------------------*\
#    --  LINK OTHER LIB  --
#*------------------------------------*/
#target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/mlx/libmlx.a)
#
#target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
#target_link_libraries(${PROJECT_NAME} "-framework AppKit")