all: compile link run

compile:
	g++ -c src/main.cpp -IC:\SFML-2.5.1\include

link:
	g++ -o MaM main.o -LC:\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	./MaM