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
Bullet::Bullet(Vector2 position, Vector2 velocity, float rotation, Texture2D sprite) : SceneObject(position, velocity, 40, 0, 0.2)
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
    if (Destroyed == false) {
        timer += deltaTime;

        float r = (Rotation - 90) / 180 * PI;
        Velocity = { (cos(r)) * speed, sin(r) * speed};
        Position.x += Velocity.x * deltaTime;
        Position.y += Velocity.y * deltaTime;
    }
    if (timer > lifeTime)
        Destroyed = true;

}

void Bullet::Draw() 
{
    if (Destroyed == false) {
        //DrawTextureEx(Sprite, Position, Rotation, Scale, WHITE);
        DrawCircleLines((int)Position.x, (int)Position.y, Radius * Scale, YELLOW);
        Rectangle sourceRect = { 0,0,(float)Sprite.width, (float)Sprite.height };
        Rectangle distRect = { Position.x, Position.y, Sprite.width * Scale, Sprite.height * Scale };
        DrawTexturePro(Sprite, sourceRect, distRect, { Sprite.width / 2 * Scale, Sprite.height / 2 * Scale }, Rotation, WHITE);
    }
}
