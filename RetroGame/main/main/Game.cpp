#include "raylib.h"
#include "Game.h"
#include <stdlib.h>

Game::Game() {}

Game::~Game() {}

void Game:: Run() 
{
	InitWindow(windowWidth, windowHeight, "Game");
	SetTargetFPS(60);

	Load();

	while (!WindowShouldClose()) {
		Update(GetFrameTime());
		Draw();
	}
	Unload();
}

void Game::Load() {
	
}

void Game::Update(float deltaTime) 
{

}

void Game::Draw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
}