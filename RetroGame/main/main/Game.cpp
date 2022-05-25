#include "raylib.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include "SceneObject.h"
#include "Ship.h"
#include "string"

Game::Game() 
{
	startPos = { 400,400 };
	asteroidTexture = LoadTexture("Assets/Asteroid.png");
	shipTexture = LoadTexture("Assets/Ship_L.png");
};

Game::~Game() {};



void Game::Load()
{	
	ship.Sprite = shipTexture;
	ship.Position = startPos;
	ship.Radius = 40;



	SpawnAsteroids();
}


void Game::SpawnAsteroids() 
{
	for (int i = 0; i < 8; i++) {
		Asteroid asteroid;
		asteroid.Sprite = asteroidTexture;
		asteroidList.push_back(asteroid);
	}
}

void Game::Update(float deltaTime)
{
	ship.Update(deltaTime);

	for (Asteroid &asteroids : asteroidList) {
		asteroids.Update(deltaTime);
		if (asteroids.CheckCollision(ship)) 
		{
			ship.Destroyed = true;
		}
		for (Bullet &bullet : bulletList) 
		{
			if (asteroids.CheckCollision(bullet))
			{
				asteroids.Destroyed = true;
			}
		}
	}
}

void Game::Draw() {
	BeginDrawing();
	ClearBackground(BLACK);

	ship.Draw();

	for (Asteroid &asteroids : asteroidList) {
		asteroids.Draw();
	}
	EndDrawing();
}

void Game::Unload() {}