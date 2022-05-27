#pragma once
#include "raylib.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Bullet.h"

class Game {
public:

	Game();
	~Game();
	void Load();
	void Unload();

	void Update(float deltaTime);
	void Draw();
	void SpawnAsteroids(int amount);

	std::vector<Bullet> bulletList;
	std::vector<Asteroid> asteroidList;
	Texture2D shipTexture;
	Texture2D asteroidTexture;
	Texture2D bulletSprite;
	Ship ship;
	float timer;
	float shootTimer;
	float shootCooldown = 0.5;
	float spawnRate = 5;
};
