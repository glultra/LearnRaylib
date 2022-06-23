all: compile run

compile:
	g++ main.cpp ./src/timer.cpp -o main -I ./deps/include/ -L ./deps/lib/ -lraylib -lshell32 -lwinmm -lgdi32 -lopengl32
run:
	.\main.exe