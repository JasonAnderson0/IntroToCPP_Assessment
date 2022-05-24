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
		float Radius;
		float Rotation;
		float Scale;

		//Texture variables
		Texture2D Sprite;

		SceneObject() {};
		SceneObject(Vector2 position, float radius, Texture2D sprite) {}

		virtual void Update(float deltaTime) 
		{
		}

		void virtual Draw() 
		{
		}

		virtual void OnCollision(SceneObject other){}
};

//struct Vector2 {
//public:
//	float x, y;
//
//	Vector2() { x = 0; y = 0;}
//	Vector2(float X, float Y) { x = X; y = Y;}
//
//	static Vector2 operator +(Vector2 lhs, Vector2 rhs)
//	{
//		return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
//	}
//
//	static Vector2 operator *(float scale, Vector2 vector)
//	{
//		return Vector2(scale * vector.x, scale * vector.y);
//	}
//};

