#include "raylib.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include "SceneObject.h"
#include "Ship.h"
#include "string"

Game::Game() 
{
	asteroidTexture = LoadTexture("Assets/Asteroid.png");
	shipTexture = LoadTexture("Assets/Ship_L.png");
	bulletSprite = LoadTexture("Assets/Bullet.png");
};

Game::~Game() {};



void Game::Load()
{	
	ship.Sprite = shipTexture;
	ship.Position = {400,400};
	ship.Radius = 40;

	SpawnAsteroids();
}


void Game::SpawnAsteroids() 
{
	for (int i = 0; i < 8; i++) {
		Asteroid asteroid;
		asteroid.Sprite = asteroidTexture;
		//asteroid.Position = { (float)100 * i, (float)100 * i };
		asteroidList.push_back(asteroid);
	}
}

void Game::Update(float deltaTime)
{
	ship.Update(deltaTime);

	for (Asteroid &asteroids : asteroidList) {
		asteroids.Update(deltaTime);
		//if (asteroids.CheckCollision(ship)) 
		//{
		//	ship.Destroyed = true;
		//}
		//for (Bullet &bullet : bulletList) 
		//{
		//	if (asteroids.CheckCollision(bullet))
		//	{
		//		asteroids.Destroyed = true;
		//	}
		//}
	}

	if (IsKeyDown(KEY_SPACE))
	{
		Bullet bullet(ship.Position, ship.Velocity, ship.Rotation, bulletSprite);
		bulletList.push_back(bullet);
	}
	for (Bullet& bullets : bulletList) {
		bullets.Update(deltaTime);
	}
}

void Game::Draw() {
	BeginDrawing();
	ClearBackground(BLACK);

	ship.Draw();

	for (Asteroid &asteroids : asteroidList) {
		asteroids.Draw();
	}
	for (Bullet& bullets : bulletList) {
		bullets.Draw();
	}
	EndDrawing();
}

void Game::Unload() {}