CXX=g++
CXXFLAGS=-g -Wall -MMD -std=c++11
#Dieses Makefile erstellt das Programm Pendel.o und verwendet dafür die angegebenen Dateien. Auf Grund des Datentyps Array muss c++11 verwendet werden.
all: Pendel.cpp Masse.cpp Draht.cpp main.cxx gnuplot_i.hpp
	g++ -std=c++11 -o Pendel.out main.cxx Pendel.cpp Masse.cpp Draht.cpp gnuplot_i.hpp