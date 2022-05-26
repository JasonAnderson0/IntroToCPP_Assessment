#include <vector>
#include <iostream>
#include<raylib.h>
#include"SceneObject.h"
#include "string"


SceneObject::SceneObject() 
{
	Position = { 0,0 };
	Velocity = {0,0};
	Radius = 0;
	Rotation = 0;
	Scale = 1;
}
SceneObject::SceneObject(Vector2 position, Vector2 velocity, float radius, float rotation,float scale) {
	Position = position;
	Velocity = velocity;
	Radius = radius;
	Rotation = rotation;
	Scale = scale;
}

void SceneObject::Update(float deltaTime)
{
	Position.x += Velocity.x * deltaTime;
	Position.y += Velocity.y * deltaTime;
}

void SceneObject::Draw()
{

}

void SceneObject::OnCollision(SceneObject other) 
{

}