#include "Bullet.h"
#include "SceneObject.h"
#include "raylib.h"


Bullet::Bullet() {}
Bullet::Bullet(Vector2 position, float rotation, Texture2D sprite)
{
}

void Bullet::Update(float deltaTime)
{
    Position.x += speed * deltaTime;
    Position.y += speed * deltaTime;
}
