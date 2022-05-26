#include "Asteroid.h"
#include "SceneObject.h"
#include "raylib.h"
#include "Ship.h"
#include "Bullet.h"

Asteroid::Asteroid() 
{
    //float Velx = (float)(rand() % 360 - 360); float Vely = (float)(rand() % 360 - 360);
    //Velocity = { Velx , Vely};
    //if (Velx == 400) Velx = 0; if (Vely == 400) Vely = 0;
    Velocity = { 10,10 };
    Position = { 0 , 0 };
    Sprite = LoadTexture("Assets/Asteroid.png");
    Scale = (float)(rand() % 3);
}
Asteroid::Asteroid(Vector2 position, Vector2 velocity, float scale, Texture2D sprite) : SceneObject(position, velocity, 40, 90, 1)
{
    Position = position;
    Velocity = velocity;
    Sprite = sprite;
    Scale = scale;
};

void Asteroid::Update(float deltaTime) 
{
    //movement
    Position.x += (Velocity.x / 5) * deltaTime;
    Position.y += (Velocity.y / 5) * deltaTime;

    float width = (float)GetScreenWidth();
    float height = (float)GetScreenHeight();

    //if (Position.x < -Radius) Position.x = width + height;
    //if (Position.y < -Radius) Position.y = -Radius;
    //if (Position.y > Radius + width) Position.y = Radius + height;
    //if (Position.x > width + Radius) Position.x = -Radius;
}

bool Asteroid::CheckCollision(Ship other) 
{
    //Vector2 obstdistx = (Position * Position - other.Position * other.Position);
    //float radii = (Radius * Radius + other.Radius * other.Radius);

    return true;
    //return(obstdist < radii);
}

bool Asteroid::CheckCollision(Bullet other) {
    float obstdistx = (Position.x * Position.x - other.Position.x * other.Position.x);
    float obstdisty = (Position.y * Position.y - other.Position.y * other.Position.y);
    float obstdist = obstdistx + obstdisty;
    float radii = Radius * Radius + other.Radius * other.Radius;


    return(obstdist < radii);
}

void Asteroid::Draw() 
{
    if (Destroyed == false) 
    {
        DrawTextureEx(Sprite, Position, Rotation, Scale, WHITE);
        DrawCircleLines((int)Position.x, (int)Position.y, Radius * Scale, YELLOW);
    }
}
