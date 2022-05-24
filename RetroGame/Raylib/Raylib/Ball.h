#pragma once
#include "SceneObject.h"
#include "Paddle.h"
#include "raylib.h"



class Ball :
    public SceneObject
{
public:
    Vector2 Direction;
    float Radius;

    Ball();
    Ball(Vector2 position, Vector2 size, Vector2 direction, float speed, float radius);

    void Update(float deltaTime) override;
    void Draw() override;
    void Collision(SceneObject other);
    void CheckCollision(Paddle other);
};

