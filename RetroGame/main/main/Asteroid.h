#pragma once
#include "SceneObject.h"
#include "raylib.h"
#include "Ship.h"
#include "Bullet.h"
class Asteroid :
    public SceneObject
{
public:
    bool Destroyed = false;
    Vector2 Velocity;
    Texture2D Sprite;
    float Speed;
    Asteroid();
    Asteroid(Vector2 position, Vector2 velocity, float scale, Texture2D sprite, float speed);

    bool CheckCollision(Bullet other);
    //bool CheckCollision(Ship other);

    void Update(float deltaTime);

    void Draw() override;
};

