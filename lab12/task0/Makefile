# Собрать многофайловый проект
# Подсказка: Опция -I в gcc помогает решить проблему с поиском заголовочных файлов. (#include "" No such file or directory)
# Для использования make его необходимо установить: sudo apt install make


main: main.o background.o read_pipe.o write_pipe.o
	gcc main.o background.o read_pipe.o write_pipe.o -o main
	
main.o: app/main.c
	gcc -I background -I pipes -c app/main.c -o main.o

background.o: background/background.c
	gcc -I background -I pipes -c background/background.c -o background.o

read_pipe.o: pipes/read_pipe.c
	gcc -I background -I pipes -c pipes/read_pipe.c -o read_pipe.o

write_pipe.o: pipes/write_pipe.c
	gcc -I background -I pipes -c pipes/write_pipe.c -o write_pipe.o
