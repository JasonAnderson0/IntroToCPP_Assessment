#pragma once
#include <vector>
#include <iostream>
#include<raylib.h>
#include "string"

class SceneObject
{
public:
		Vector2 Position = {0,0};
		Vector2 Velocity = {0,0};
		float Radius;
		float Rotation;
		float Scale;

		class SceneObject();
		class SceneObject(Vector2 position,Vector2 velocity, float radius,float rotation, float scale);

		virtual void Update(float deltaTime);

		virtual void Draw();
};

