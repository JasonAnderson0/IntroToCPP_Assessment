#include "Ball.h"
#include "raylib.h"


Ball::Ball() {};
Ball::Ball(Vector2 position, Vector2 size, Vector2 direction, float speed, float radius) {
	Position = position;
	Size = size;
	Direction = direction;
	Speed = speed;
	Radius = radius;
}

void Ball::Update(float deltaTime) 
{
	Position.x *= Direction.x * Speed;
	Position.y *= Direction.y * Speed;
}

void Ball:: Draw() 
{
	DrawRectangleV(Position, Size, WHITE);
}

void Ball::Collision(SceneObject other) 
{

}

void Ball::CheckCollision(Paddle other) 
{

}

//float x = 150;
//float y = 100;
//float xSpeed = 5;
//float ySpeed = 4;
//
//void setup() {
//	size(300, 300);
//}
//
//void draw() {
//	background(64);
//	ellipse(x, y, 25, 25);
//
//	x += xSpeed;
//	y += ySpeed;
//
//	if (x < 0 || x > width) {
//		xSpeed *= -1;
//	}
//
//	if (y < 0 || y > height) {
//		ySpeed *= -1;
//	}
//}


