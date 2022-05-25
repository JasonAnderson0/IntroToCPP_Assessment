#include "Bullet.h"
#include "SceneObject.h"
#include "raylib.h"


Bullet::Bullet() { timer = 0; }
Bullet::Bullet(Vector2 position, float rotation, Texture2D sprite)
{
    timer = 0;
}

void Bullet::Update(float deltaTime)
{
    Position.x += speed * deltaTime;
    Position.y += speed * deltaTime;
}
