#include "Bullet.h"
#include "SceneObject.h"
#include "raylib.h"


Bullet::Bullet() 
{ 
    timer = 0; 
    Destroyed = false;
    Velocity = { 0,0 };
    Sprite = LoadTexture("Assets/Bullet.png");
}
Bullet::Bullet(Vector2 position, Vector2 velocity, float rotation, Texture2D sprite) : SceneObject(position, velocity, 5, 0, 0.1f)
{
    Position = position;
    Velocity = velocity;
    Rotation = rotation;
    Sprite = sprite;
    timer = 0;
    Destroyed = false;

}

void Bullet::Update(float deltaTime)
{
    float r = (Rotation - 90) / 180 * PI;
    //Position = { (cos(r)) * speed, sin(r) * speed};

}

void Bullet::Draw() 
{
    if (Destroyed == false) {
        DrawTextureEx(Sprite, Position, Rotation, Scale, WHITE);
        DrawCircleLines((int)Position.x, (int)Position.y, Radius * Scale, YELLOW);
    }
}
