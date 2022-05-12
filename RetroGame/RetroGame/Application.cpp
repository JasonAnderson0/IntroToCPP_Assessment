#include "Application.h"
#include "raylib.h"
#include <stdlib.h>

	Application::Application() {}
	Application::~Application() {}

	void Application::Run() 
	{
		InitWindow(windowWidth, windowHeight, "Snake Game");
		SetTargetFPS(60);

		Load();

		while (!WindowShouldClose()) {
			Update(GetFrameTime());
			Draw();
		}

		Unload();
	}

	void Application::Load() {

	}

	void Application::Unload() {

	}

	void Application::Update(float deltaTime) {
		//make head move in direction, make body go to last location of body part before it

	}

	void Application::Draw() 
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
			for (int colIndex = 0; colIndex < cols; colIndex++) {

				int xPos = colIndex * tileWidth;
				int yPos = rowIndex * tileHeight;
				Color color = GetTileColor(tiles[xPos][yPos]);

				DrawRectangle(xPos, yPos, tileWidth, tileHeight, color);
			}
		}

		EndDrawing();
	}

	Color Application::GetTileColor(int tileValue) {
		switch (tileValue) {
		case 0: return YELLOW;
		case 1: return WHITE;
		}
	}