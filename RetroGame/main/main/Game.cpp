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
	timer = 0;
};

Game::~Game() {};



void Game::Load()
{	
	SpawnAsteroids(8);
}


void Game::SpawnAsteroids(int amount) 
{
	for (int i = 0; i < amount; i++) {
		Asteroid asteroid;
		asteroid.Sprite = asteroidTexture;
		asteroidList.push_back(asteroid);
	}
}

void Game::Update(float deltaTime)
{
	ship.Update(deltaTime);
	timer += deltaTime;
	shootTimer += deltaTime;
	for (Asteroid &asteroids : asteroidList) {
		asteroids.Update(deltaTime);
		if (asteroids.CheckCollision(ship) && asteroids.Destroyed == false) 
		{
			ship.Destroyed = true;
		}
		for (Bullet &bullet : bulletList) 
		{
			if (asteroids.CheckCollision(bullet) && asteroids.Destroyed == false)
			{
				asteroids.Destroyed = true;
			}
		}
	}

	if (IsKeyDown(KEY_SPACE) && ship.canShoot == true)
	{
		ship.canShoot = false;
		shootTimer = 0;
		Bullet bullet(ship.Position, ship.Velocity, ship.Rotation, bulletSprite);
		bulletList.push_back(bullet);
	}
	for (Bullet& bullets : bulletList) {
		bullets.Update(deltaTime);
	}

	if(timer > spawnRate)
	{
		timer = 0;
		SpawnAsteroids(1);
	}
	if(shootTimer > shootCooldown)
	{
		ship.canShoot = true;
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