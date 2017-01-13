OPT=-Wall --std=c++11


all : main

main: main.o monde.o candidat.o element.o obstacle.o bonus.o raciste.o fasciste.o sauveur.o bonus_inv.o bonus_vie.o
	g++ $(OPT) main.o monde.o candidat.o element.o obstacle.o bonus.o raciste.o fasciste.o sauveur.o bonus_vie.o bonus_inv.o -lsfml-graphics -lsfml-window -lsfml-system -o main 

main.o: main.cpp monde.hpp candidat.hpp
	g++ $(OPT) -c main.cpp

monde.o: monde.cpp monde.hpp
	g++ $(OPT) -c monde.cpp

candidat.o: candidat.cpp candidat.hpp
	g++ $(OPT) -c candidat.cpp
	
element.o: element.cpp element.hpp
	g++ $(OPT) -c element.cpp
	
obstacle.o: obstacle.cpp obstacle.hpp
	g++ $(OPT) -c obstacle.cpp
	
bonus.o: bonus.cpp bonus.hpp
	g++ $(OPT) -c bonus.cpp
	
bonus_inv.o: bonus_inv.cpp bonus_inv.hpp
	g++ $(OPT) -c bonus_inv.cpp
	
bonus_vie.o: bonus_vie.cpp bonus_vie.hpp
	g++ $(OPT) -c bonus_vie.cpp

raciste.o : raciste.cpp raciste.hpp
	g++ $(OPT) -c raciste.cpp
	
fasciste.o : fasciste.cpp fasciste.hpp
	g++ $(OPT) -c fasciste.cpp

sauveur.o : sauveur.cpp sauveur.hpp
	g++ $(OPT) -c sauveur.cpp


clean:
	rm -f *o
