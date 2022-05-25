#pragma once
#include "SceneObject.h"
#include "raylib.h"

class Bullet :
    public SceneObject
{
private:
    const float lifeTime = 3;
    const float speed = 30;
    float timer;

public:
    Bullet();
    Bullet(Vector2 position, float rotation, Texture2D sprite);
    void Update(float deltaTime) override;
};

