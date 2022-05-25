#include "SceneObject.h"
#include "raylib.h"
#include "Ship.h"
#include "Bullet.h"


Ship::Ship() {}
Ship::Ship(Vector2 position, Texture2D sprite, float rotation) : SceneObject(position, 40, sprite, 90, 1)
{
	Position = position;
	Sprite = sprite;
	Rotation = rotation;

	bulletSprite = LoadTexture("Assets/Bullet.png");
}


void Ship::Update(float deltaTime)
{
	SceneObject::Update(deltaTime);
	float thrust = IsKeyDown(KEY_UP) ? 1 : 0;
	//float r = (Rotation - 90) / 180 * PI;
	//Vector2 force = (Cos(r), Sin(r)) * speed * thrust;
	Position.x += speed * thrust * deltaTime;
	Position.y += speed * thrust * deltaTime;

	if(IsKeyDown(KEY_SPACE))
	{
		Bullet bullet(Position, Rotation, bulletSprite);
	}
}

void Ship::Draw() 
{
	if (Destroyed == false) {
		DrawTextureEx(Sprite, Position, Rotation, Scale, WHITE);
		DrawCircleLines((int)Position.x, (int)Position.y, Radius * Scale, YELLOW);
	}
}