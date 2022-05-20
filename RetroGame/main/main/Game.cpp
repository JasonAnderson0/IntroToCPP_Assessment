#include "raylib.h"
#include "Game.h"
#include <stdlib.h>
#include <vector>
#include "SceneObject.h"
using namespace std;


	Game::Game() {}

	Game::~Game() {}

	vector<SceneObject> gameObjects;

	void Load()
	{

	}

	void Update(float deltaTime)
	{

	}

	void Draw() {
		BeginDrawing();
		ClearBackground(RAYWHITE);
	}