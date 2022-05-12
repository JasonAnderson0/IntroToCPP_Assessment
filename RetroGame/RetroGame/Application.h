#pragma once
#include "raylib.h"

class Application 
{
public:
	Application();
	~Application();

	void Run();

private:
	void Load();
	void Unload();

	void Update(float deltaTime);
	void Draw();

	Color GetTileColor(int tileValue);

private: 
	int windowHeight = 800;
	int windowWidth = 800;

	static const int rows = 40;
	static const int cols = 40;

	int tiles[rows][cols] = 
	{
		{00,01,02},
		{10,11,12},
		{20,21,22}
	};

	int tileWidth = 20;
	int tileHeight = 20;
};

