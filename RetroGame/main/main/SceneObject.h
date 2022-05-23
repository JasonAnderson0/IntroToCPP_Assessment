#pragma once
#include <vector>
#include <iostream>
#include<raylib.h>
using namespace std;

class SceneObject
{
public:
		//transform variables
		Vector2 Position;
		Vector2 Velocity; 
		float Radius = 0;
		float Rotation = 0;
		float Scale = 1;

		//Texture variables
		Texture2D Sprite;

		SceneObject() {};
		SceneObject(Vector2 position, float radius, Texture2D sprite) {
			Position = position;
			Radius = radius;
			Sprite = sprite;
		}

		virtual void Update(float deltaTime) 
		{
			//Position += Velocity , deltaTime;
		}

		void virtual Draw() 
		{
			DrawTextureEx(Sprite, Position, Rotation, Scale, WHITE);
			DrawCircleLines((int)Position.x, (int)Position.y, Radius * Scale, YELLOW);
		}

		virtual void OnCollision(SceneObject other){}
};

