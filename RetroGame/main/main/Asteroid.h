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
    Vector2 Direction;
    Asteroid();
    Asteroid(Vector2 position, float scale, Texture2D sprite, Vector2 direction);

    bool CheckCollision(Bullet other);
    bool CheckCollision(Ship other);

    void Update(float deltaTime);

    void Draw() override;
};

