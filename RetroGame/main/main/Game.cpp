#include "raylib.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include "SceneObject.h"
#include "Ship.h"
#include "string"
#include <list>
using namespace std;

Game::Game() {};

Game::~Game() {};

	vector<SceneObject> gameObjects;
	//list<SceneObject> gameObjects;
	vector<SceneObject> asteroidList;

	void Game::Load()
	{
		Texture2D shipTexture = LoadTexture("Assets/ship_L.png");
		Vector2 startPos = { 400,400 };
		Ship ship(startPos, shipTexture);
		Ship &playerShip = ship;
		if (&shipTexture != NULL) {
			cout << "Found";
		}
		gameObjects.push_back(playerShip);
	}

	void Game::Update(float deltaTime)
	{
		for (SceneObject sceneObject : gameObjects) {
			//if(sceneObject is Ship)
			sceneObject.Position.x = 400;
			sceneObject.Position.y = 400;
		}

		for (SceneObject object : gameObjects) {
			object.Update(deltaTime);
		}

	}

	void Game::Draw() {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		for (SceneObject object : gameObjects) {
			object.Draw();
		}
		EndDrawing();
	}