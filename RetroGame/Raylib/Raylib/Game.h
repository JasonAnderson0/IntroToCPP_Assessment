#pragma once
#include "raylib.h"

class Game
{
public:
	Game();
	~Game();
	void Load();
	void Update(float deltaTime);
	void Update();
	void Draw();

};

