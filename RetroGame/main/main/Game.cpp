#include "raylib.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include "SceneObject.h"
#include "Ship.h"
#include "string"

Game::Game() 
{

};

Game::~Game() {};



void Game::Load()
{	
	shipTexture = LoadTexture("Assets/Ship_L");
	ship().Position = startPos;


	asteroidTexture = LoadTexture("Assets/Asteroid");

	SpawnAsteroids();
}


void Game::SpawnAsteroids() 
{
	for (int i = 0; i < 8; i++) {
		Asteroid asteroid();

		//asteroidList.push_back(asteroid);
	}
}

void Game::Update(float deltaTime)
{
	ship().Update(deltaTime);

	for (Asteroid asteroids : asteroidList) {
		asteroids.Update(deltaTime);
		if (asteroids.CheckCollision(ship)) 
		{
			ship.Destroyed = true;
		}
		for (Bullet bullet : bulletList)
		if(asteroids.CheckCollision(bullet))
		{
			asteroids.Destroyed = true;
		}
	}
}

void Game::Draw() {
	BeginDrawing();
	ClearBackground(BLACK);

	ship().Draw();

	for (Asteroid asteroids : asteroidList) {
		asteroids.Draw();
	}
	EndDrawing();
}