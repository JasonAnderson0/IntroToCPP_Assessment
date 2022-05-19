#pragma once
#include "raylib.h"

class Game {
public:
	Game();
	~Game();

	void Run();

private:
	void Load();
	void Unload();

	void Update();

	void Update(float deltaTime);
	void Draw();

private: 
	int windowWidth = 800;
	int windowHeight = 800;
};
