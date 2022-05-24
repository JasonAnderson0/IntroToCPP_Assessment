#pragma once
#include "raylib.h"



class SceneObject
{
public:
	Vector2 Position;
	Vector2 Size;
	float Speed;

	SceneObject();
	SceneObject(Vector2 position, Vector2 size, float speed);
	void virtual Update(float deltaTime);
	void virtual Draw();
};

