#include "SceneObject.h"
#include "raylib.h"
#include "Ship.h"
#include "Bullet.h"
#include <cmath>


Ship::Ship() 
{
	Position = { 400,400 };
	Velocity = { 0,0 };
	radius = 40;
	Speed = 300;
	Destroyed = false;
	Sprite = LoadTexture("Assets/Ship_L.png");
}
Ship::Ship(Vector2 position, Vector2 velocity, Texture2D sprite, float rotation, float speed) : SceneObject(position, velocity, 40, 90, 1)
{
	Position = position;
	Sprite = sprite;
	Rotation = rotation;
	Velocity = velocity;
	Destroyed = false;
	Speed = speed;
	radius = 40;
}


void Ship::Update(float deltaTime)
{
	SceneObject::Update(deltaTime);
	float turn = 0;
	if (IsKeyDown(KEY_LEFT)) turn -= 1;
	if (IsKeyDown(KEY_RIGHT)) turn += 1;

	int thrust = IsKeyDown(KEY_UP) ? 1 : 0;

	float r = (Rotation - 90) / 180 * PI;
	Vector2 force = { (cos(r)) * Speed * thrust, sin(r) * Speed * thrust };

	Position.x += force.x * deltaTime;
	Position.y += force.y * deltaTime;

	Rotation += turn * turnSpeed * deltaTime;

	float width = (float)GetScreenWidth();
	float height = (float)GetScreenHeight();

	if (Position.x < -Radius) Position.x = width + height;
	if (Position.y < -Radius) Position.y = -Radius;
	if (Position.y > Radius + width) Position.y = Radius + height;
	if (Position.x > width + Radius) Position.x = -Radius;
}

void Ship::Draw() 
{
	if (Destroyed == false) {
		DrawTextureEx(Sprite, Position, Rotation, Scale, WHITE);
		DrawCircleLines((int)Position.x, (int)Position.y, Radius * Scale, YELLOW);
	}
}