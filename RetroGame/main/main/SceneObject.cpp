#include <vector>
#include <iostream>
#include<raylib.h>
#include"SceneObject.h"

//Constructors
SceneObject::SceneObject() 
{
	//variables initialized as a default value
	Position = { 0,0 };
	Velocity = {0,0};
	Radius = 0;
	Rotation = 0;
	Scale = 1;
}
SceneObject::SceneObject(Vector2 position, Vector2 velocity, float radius, float rotation,float scale) 
{
	//variables initialized based on their input
	Position = position;
	Velocity = velocity;
	Radius = radius;
	Rotation = rotation;
	Scale = scale;
}

//base Update function for child classes that are inheriting this to use
void SceneObject::Update(float deltaTime)
{
	Position.x += Velocity.x * deltaTime;
	Position.y += Velocity.y * deltaTime;
}

//base Draw function for child classes that are inheriting this to use
void SceneObject::Draw()
{

}
