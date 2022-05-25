#include <vector>
#include <iostream>
#include<raylib.h>
#include"SceneObject.h"
#include "string"


SceneObject::SceneObject() {}
SceneObject::SceneObject(Vector2 position, float radius, Texture2D sprite, float rotation,float scale) {
	Position = position;
	Radius = radius;
	Sprite = sprite;
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