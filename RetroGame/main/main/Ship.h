#pragma once
#include "SceneObject.h"
#include "raylib.h"


class Ship : public SceneObject
{
public: 
	const float turnSpeed = 180;
	bool canShoot;
	float Speed;
	float radius;
	Vector2 Position;
	Vector2 Velocity;
	Texture2D Sprite;
	Texture2D bulletSprite = LoadTexture("Assets/Bullet.png");
	bool Destroyed;
	
	Ship();
	Ship(Vector2 position, Vector2 velocity, Texture2D sprite, float rotation,float speed);

	
	void Update(float deltaTime) override;
	void Draw() override;
};