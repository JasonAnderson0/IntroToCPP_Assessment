#pragma once
#include "raylib.h"

class Game {
public:
	Game();
	~Game();
	void Load();
	void Unload();

	void Update();

	void Update(float deltaTime);
	void Draw();

};
