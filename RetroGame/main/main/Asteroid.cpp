#include "Asteroid.h"
#include "SceneObject.h"
#include "raylib.h"
#include "Ship.h"
#include "Bullet.h"

Asteroid::Asteroid() 
{
    float Velx = (float)(rand() % 100 - 50);
    Velocity = { Velx , Velx};
    float Posx = (float)(rand() % GetScreenWidth());
    if (Posx < 500 && Posx > 400) {
        Posx -= 100;
    }
    Position = { Posx , Posx };
    Sprite = LoadTexture("Assets/Asteroid.png");
    Scale = (float)(rand() % 3);
    Speed = (float)(rand() & 20 - 10);
    Radius = 40;
}
Asteroid::Asteroid(Vector2 position, Vector2 velocity, float scale, Texture2D sprite, float speed) : SceneObject(position, velocity, 40, 90, 1)
{
    Position = position;
    Velocity = velocity;
    Sprite = sprite;
    Scale = scale;
    Speed = speed;
};

void Asteroid::Update(float deltaTime) 
{
    //movement
    Position.x += Velocity.x * Speed * deltaTime;
    Position.y += Velocity.y * deltaTime;

    float width = (float)GetScreenWidth();
    float height = (float)GetScreenHeight();

    float w = (float)GetScreenWidth();
    float h = (float) GetScreenHeight();



    Vector2 p = Position;
    if (Position.x < -Radius) p.x = w + Radius;
    if (Position.y < -Radius) p.y = w + Radius;
    if (Position.x > w + Radius) p.x = -Radius;
    if (Position.y > w + Radius) p.y = -Radius;

    Position = p;
}

//bool Asteroid::CheckCollision(Ship other) 
//{
//    float obstx = (Position.x * Position.x - other.Position.x * other.Position.x);
//    float obsty = (Position.y * Position.y - other.Position.y * other.Position.y);
//    float obstdist = obstx - obsty;
//    float rads = (Radius * Radius + other.Radius * other.Radius);
//
//
//
//    //return true;
//    return(obstdist < rads * rads);
//}

bool Asteroid::CheckCollision(Bullet other) {
    float obstx = (Position.x * Position.x - other.Position.x * other.Position.x);
    float obsty = (Position.y * Position.y - other.Position.y * other.Position.y);
    float obstdist = obstx + obsty;
    float rads = Radius + other.Radius;



    //return true;
    return(obstx < rads * rads && obsty < rads * rads);
}

void Asteroid::Draw() 
{
    if (Destroyed == false) 
    {
        DrawTextureEx(Sprite, Position, Rotation, Scale, WHITE);
        DrawCircleLines((int)Position.x, (int)Position.y, Radius, YELLOW);
    }
}
