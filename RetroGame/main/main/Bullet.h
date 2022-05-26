#pragma once
#include "SceneObject.h"
#include "raylib.h"

class Bullet :
    public SceneObject
{
private:
    const float lifeTime = 5;
    const float speed = 250;
    float timer;
    bool Destroyed;
    Texture2D Sprite;
    Vector2 Velocity;

public:
    Bullet();
    Bullet(Vector2 position, Vector2 velocity, float rotation, Texture2D sprite);
    void Update(float deltaTime) override;
    void Draw() override;
};