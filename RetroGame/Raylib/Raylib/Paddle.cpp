#include "Paddle.h"
#include "raylib.h"

Paddle::Paddle() {};
Paddle::Paddle(Vector2 position, Vector2 size, float speed, int playernumb) {
	Position = position;
	Size = size;
	Speed = speed;
	playerNumb = playernumb;
}

void Paddle::Update(float deltaTime)
{
	if (playerNumb == 1) 
	{
		if (IsKeyDown(KEY_UP))
			Position.y += Speed * deltaTime;
		if (IsKeyDown(KEY_DOWN))
			Position.y -= Speed * deltaTime;
	}
	else {
		if (IsKeyDown(KEY_W))
			Position.y += Speed * deltaTime;
		if (IsKeyDown(KEY_S))
			Position.y -= Speed * deltaTime;
	}
}

void Paddle::Draw() 
{
	DrawRectangleV(Position, Size, YELLOW);
}
