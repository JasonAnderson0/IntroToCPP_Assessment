#pragma once
#include "SceneObject.h"
#include "raylib.h"
#include <cmath>

class Bullet :
    public SceneObject
{
private:
    float lifeTime = 3;
    float timer;

public:
    Bullet(Vector2 position, float rotation, float speed, Texture2D sprite)
    {
        Rotation = rotation;
        float r = (Rotation - 90) / 180 * PI;
        Velocity = Vector2(Cos(r), Sin(r)) * speed;
    }

};

