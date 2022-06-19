#include <iostream>
#include "raylib.h"


int main() {
	InitWindow(600, 600, "My Raylib");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RED);
		EndDrawing();
	}
}