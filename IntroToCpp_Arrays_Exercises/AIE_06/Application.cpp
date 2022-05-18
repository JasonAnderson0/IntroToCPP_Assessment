#include "Application.h"
#include "raylib.h"
#include <stdlib.h>


Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Simple Tilemap");
	SetTargetFPS(60);

	Load();

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}

	Unload();
}

void Application::Load()
{
	for (int i = 0; i < ROWS * COLS; i++) 
	{
		m_tiles[i] = rand() % 5;
	}
}

void Application::Unload()
{

}

void Application::Update(float deltaTime)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();
		int rowIndex = mousePos.y / m_tileWidth; 
		int colIndex = mousePos.x / m_tileHeight;

		int tileIndex = rowIndex * COLS + colIndex;

		m_tiles[tileIndex] += 1;
		if (m_tiles[tileIndex] >= 5)
			m_tiles[tileIndex] = 0;
	}
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	for (int rowIndex = 0; rowIndex < ROWS; rowIndex++){
		for (int colIndex = 0; colIndex < COLS; colIndex++) {

			int xPos = colIndex * m_tileWidth;
			int yPos = rowIndex * m_tileHeight;
			int index = rowIndex * COLS + colIndex;
			Color color = GetTileColor(m_tiles[index]);

			DrawRectangle(xPos, yPos, m_tileWidth, m_tileHeight, color);
		}
	}
	EndDrawing();
}

Color Application::GetTileColor(int tileValue)
{
	switch (tileValue)
	{
	case 0: return WHITE;
	case 1: return RED;
	case 2: return GREEN;
	case 3: return BLUE;
	case 4: return YELLOW;
	}
	
	return BLACK;
}