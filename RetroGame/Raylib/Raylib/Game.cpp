#include "Game.h"
#include "raylib.h"
#include "Paddle.h"
#include <iostream>
#include "SceneObject.h"
#include <vector>
#include "Ball.h"
#include <typeinfo>

Game::Game() {};
Game::~Game() {};

std::vector<SceneObject> gameObjects;

void Game::Load()
{
	Vector2 startPos1 = { 10,350 };
	Vector2 size = { 20,100 };
	Vector2 startPos2 = { 790,350 };
	Vector2 ballPos = { 400, 400 };
	Vector2 ballSize = { 20,20 };
	Vector2 startDirection = { 10,10 };
	Paddle paddle1(startPos1, size, 50, 1);
	Paddle paddle2(startPos2, size, 50, 2);
	Ball ball(ballPos, ballSize, startDirection, 20, 20);
	gameObjects.push_back(paddle1);
	gameObjects.push_back(paddle2);
	gameObjects.push_back(ball);
}

void Game::Update(float deltaTime) 
{
	for (SceneObject object : gameObjects) {
		object.Update(deltaTime);
	}
	for (SceneObject object : gameObjects)
	{
		if(typeid(object) == typeid(Ball))
		for(SceneObject otherobj : gameObjects)
		if(typeid(otherobj) == typeid(Paddle))
		((Ball)object).CheckCollision(otherobj);
	}
	
}

void Game::Draw() {
	BeginDrawing();
	ClearBackground(BLACK);
	for (SceneObject object : gameObjects) {
		if (typeid(object) == typeid(Paddle))
		((Paddle)object).Draw();

		if(typeid(object) == typeid(Ball))
		((Ball)object).Draw();
	}
	EndDrawing();
}
