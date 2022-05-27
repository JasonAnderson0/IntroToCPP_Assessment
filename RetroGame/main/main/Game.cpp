#include "raylib.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include "SceneObject.h"
#include "Ship.h"

//Constructors
Game::Game() 
{
	asteroidTexture = LoadTexture("Assets/Asteroid.png");
	shipTexture = LoadTexture("Assets/Ship_L.png");
	bulletSprite = LoadTexture("Assets/Bullet.png");
	timer = 0;
	shootTimer = 0;
};
Game::~Game() {};


//First function that is called on start up. spawns 8 asteroids to begin with
void Game::Load()
{	
	SpawnAsteroids(8);
}

//When called will create an asteroid object and add it to the list of asteroids
void Game::SpawnAsteroids(int amount) 
{
	for (int i = 0; i < amount; i++) {
		Asteroid asteroid;
		asteroid.Sprite = asteroidTexture;
		asteroidList.push_back(asteroid);
	}
}

//constantly being called while game is running
void Game::Update(float deltaTime)
{
	//Function also calls update for every object

	//increases the timers for objects depending on the games lifetime
	timer += deltaTime;
	shootTimer += deltaTime;

	for (Asteroid &asteroids : asteroidList) {
		//will call the update function for every object in the asteroid list
		asteroids.Update(deltaTime);
		//checks if the ships collider is overlapping with any asteroid that is not destroyed
		if (asteroids.CheckCollision(ship) && asteroids.Destroyed == false) 
		{
			//will destroy the ship if the objects were colliding
			ship.Destroyed = true;
		}
		for (Bullet &bullet : bulletList) 
		{
			//checks if the bullets collider is overlapping with any asteroid that is not destroyed
			if (asteroids.CheckCollision(bullet) && asteroids.Destroyed == false)
			{
				//will destroy the asteroid if the objects were colliding
				asteroids.Destroyed = true;
			}
		}
		ship.Update(deltaTime);
	}

	//if the player presses space and the player is able to shoot
	//will set variables to make player wait before being able to shoot again
	//as well as creating a bullet object and passing in the ships  values
	//to the bullets constructor and also adding each
	//bullet to the list of bullets for update and draw to be called every frame
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

	//if enough time has passed, program will spawn another asteroid
	if(timer > spawnRate)
	{
		timer = 0;
		SpawnAsteroids(1);
	}
	//if enough time has passed since the last time the player has shot,
	//program will allow them to shoot again
	if(shootTimer > shootCooldown)
	{
		ship.canShoot = true;
	}
}

//constantly being called while game is running
void Game::Draw() {
	//Function also calls draw for every object
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