#pragma once
#include "SceneObject.h"
#include "raylib.h"


class Ship : public SceneObject
{
public: 
	const float turnSpeed = 180;
	const float speed = 100;
	const float radius = 40;
	Vector2 Position = { 400,400 };
	Texture2D bulletSprite = LoadTexture("Assets/Bullet.png");
	bool Destroyed = false;
	
	Ship();
	Ship(Vector2 position, Texture2D sprite, float rotation);

	
	void Update(float deltaTime) override;
	void Draw() override;
};