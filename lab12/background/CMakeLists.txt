# Задание: Создать библиотеку из background.c и слинковать ее с библиотекой pipes
set(SOURCE_LIB background.c)	
add_library(BACK_LIB SHARED ${SOURCE_LIB})