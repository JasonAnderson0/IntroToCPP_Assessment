#pragma once
#include <vector>
#include <iostream>
#include<raylib.h>
#include "string"

class SceneObject
{
public:
		//transform variables
		Vector2 Position;
		Vector2 Velocity; 
		float Radius;
		float Rotation;
		float Scale;

		//Texture variables
		Texture2D Sprite;

		SceneObject();
		SceneObject(Vector2 position, float radius, Texture2D sprite, float rotation, float scale);

		virtual void Update(float deltaTime);

		virtual void Draw();

		virtual void OnCollision(SceneObject other);
};

