project(lem_in__lib)


file(GLOB SOURCES_FILES_1 "*.c")
file(GLOB SOURCES_FILES_2 "/**/*.c")
file(GLOB SOURCES_FILES_3 "/**/**/*.c")
file(GLOB SOURCES_FILES_4 "/**/**/**/*.c")

add_library(lem_in__lib STATIC
        ${SOURCES_FILES_1}
        ${SOURCES_FILES_2}
        ${SOURCES_FILES_3}
        ${SOURCES_FILES_4}
        )

#*------------------------------------*\
#    link avec les lib
#*------------------------------------*/
target_link_libraries(lem_in__lib libft)
target_include_directories(lem_in__lib PUBLIC includes)
