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
	Speed = 200;
	Destroyed = false;
	Sprite = LoadTexture("Assets/Ship_L.png");
	Scale = 1;
	canShoot = true;
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
	canShoot = true;
}


void Ship::Update(float deltaTime)
{

	if (Destroyed == false) {
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

		float w = (float)GetScreenWidth();
		float h = (float)GetScreenHeight();



		Vector2 p = Position;
		if (Position.x < -Radius) p.x = w + Radius;
		if (Position.y < -Radius) p.y = w + Radius;
		if (Position.x > w + Radius) p.x = -Radius;
		if (Position.y > w + Radius) p.y = -Radius;

		Position = p;
	}
	else {
		canShoot = false;
	}
}

void Ship::Draw() 
{
	if (Destroyed == false) {
		Rectangle sourceRect = { 0,0,(float)Sprite.width, (float)Sprite.height };
		Rectangle distRect = { Position.x, Position.y, Sprite.width * Scale, Sprite.height * Scale};
		DrawTexturePro(Sprite, sourceRect, distRect, { Sprite.width / 2 * Scale, Sprite.height / 2 * Scale }, Rotation, WHITE);
		DrawCircleLines((int)Position.x, (int)Position.y, Radius * Scale, YELLOW);
	}
}