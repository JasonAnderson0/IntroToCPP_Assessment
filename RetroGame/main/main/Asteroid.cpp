#include "Asteroid.h"
#include "SceneObject.h"
#include "raylib.h"
#include <typeinfo>
#include "Ship.h"
#include "Bullet.h"

Asteroid::Asteroid() {}
Asteroid::Asteroid(Vector2 position, float scale, Texture2D sprite, Vector2 direction) : SceneObject(position, 40, sprite, 90, 1)
{
    Position = position;
    Sprite = sprite;
    Scale = scale;
    Direction = direction;
    
};

void Asteroid::Update(float deltaTime) 
{
    //movement
    Position.x += Direction.x * deltaTime;
    Position.y += Direction.y * deltaTime;
}

bool Asteroid::CheckCollision(Ship other) 
{
    float obstdistx = (Position.x * Position.x - other.Position.x * other.Position.x);
    float obstdisty = (Position.y * Position.y - other.Position.y * other.Position.y);
    float obstdist = obstdistx + obstdisty;
    float radii = (Radius * Radius + other.Radius * other.Radius);


    return(obstdist < radii);
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
