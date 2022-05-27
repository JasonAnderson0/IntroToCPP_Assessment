#include "SceneObject.h"
#include "raylib.h"
#include "Ship.h"
#include "Bullet.h"
#include <cmath>

//Constructors
Ship::Ship() 
{
	//variables initialized as a default value
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
	//variables initialized based on their input
	Position = position;
	Sprite = sprite;
	Rotation = rotation;
	Velocity = velocity;
	Destroyed = false;
	Speed = speed;
	radius = 40;
	canShoot = true;
}


//Update function called every frame if the object is not destroyed
void Ship::Update(float deltaTime)
{

	if (Destroyed == false) {
		float turn = 0;
		//sets the turn value depending which direction key is pressed
		if (IsKeyDown(KEY_LEFT)) turn -= 1;
		if (IsKeyDown(KEY_RIGHT)) turn += 1;

		//set variable depending if forward key is pressed preventing movement if its not pressed
		int thrust = IsKeyDown(KEY_UP) ? 1 : 0;

		float r = (Rotation - 90) / 180 * PI;


		//will constantly move ship depending on force varable
		//force variable will be set to 0 if forward key is not pressed
		Vector2 force = { (cos(r)) * Speed * thrust, sin(r) * Speed * thrust };
		Position.x += force.x * deltaTime;
		Position.y += force.y * deltaTime;

		//Updating rotation based on direcion at a set speed
		Rotation += turn * turnSpeed * deltaTime;


		//will allow ships to wrap around the screen if they move too far instead of getting lost
		float w = (float)GetScreenWidth();
		float h = (float)GetScreenHeight();

		Vector2 p = Position;
		if (Position.x < -Radius) p.x = w + Radius;
		if (Position.y < -Radius) p.y = w + Radius;
		if (Position.x > w + Radius) p.x = -Radius;
		if (Position.y > w + Radius) p.y = -Radius;

		Position = p;
	}
	//disables shooting if object is destroyed
	else {
		canShoot = false;
	}
}

//called every frame to draw the sprite at the objects current position
//as well as its collider if the object is not destroyed
//draws sprite at an offset because raylib draws from top left corner
void Ship::Draw() 
{
	if (Destroyed == false) {
		Rectangle sourceRect = { 0,0,(float)Sprite.width, (float)Sprite.height };
		Rectangle distRect = { Position.x, Position.y, Sprite.width * Scale, Sprite.height * Scale};
		DrawTexturePro(Sprite, sourceRect, distRect, { Sprite.width / 2 * Scale, Sprite.height / 2 * Scale }, Rotation, WHITE);
		DrawCircleLines((int)Position.x, (int)Position.y, Radius * Scale, YELLOW);
	}
}