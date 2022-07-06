git clone https://github.com/raysan5/raylib
cd raylib/src
sudo apt update
sudo apt install libx11-dev -y
sudo apt install libxrandr-dev -y
sudo apt install libxinerama-dev -y
sudo apt install libxcursor-dev -y
sudo apt install libxi-dev -y
sudo apt install libegl1-mesa-dev -y
make
cd ../../
mkdir myraylib
mkdir myraylib/deps/
mkdir myraylib/deps/include
mkdir myraylib/deps/lib
cp raylib/src/libraylib.a ./myraylib/deps/lib
cp raylib/src/*.h ./myraylib/deps/include
cd myraylib
touch main.cpp
echo "#include <raylib.h>" > main.cpp
echo "int main(){" >> main.cpp
echo "	InitWindow(600,600,\"Raylib\");" >> main.cpp
echo "	while(!WindowShouldClose()){" >> main.cpp
echo "		BeginDrawing();" >> main.cpp
echo "			ClearBackground(WHITE);" >> main.cpp
echo "			DrawRectangle(250, 250, 100, 100, ORANGE);" >> main.cpp
echo "		EndDrawing();" >> main.cpp
echo "	}" >> main.cpp
echo "}" >> main.cpp
touch Makefile
echo "all: compile run" > Makefile
echo "compile:" >> Makefile
echo "	g++ main.cpp -o main -I ./deps/include/ -L ./deps/lib/ -lraylib -lGL -lm -lpthread -ldl -lrt" >> Makefile
echo "run:" >> Makefile
echo "	./main" >> Makefile
make
