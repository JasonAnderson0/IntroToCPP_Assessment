#include "SceneObject.h"
#include <iostream>

	Vector2 Position = { (float)5, (float)5 };
	Vector2 Size = { 50,100 };
	float Speed;

	SceneObject::SceneObject() {};
	SceneObject::SceneObject(Vector2 position, Vector2 size, float speed)
	{
		Position = position;
		Size = size;
		Speed = speed;
	};

	void SceneObject::Update(float deltaTime) {
	}

	void SceneObject::Draw() {

	}



