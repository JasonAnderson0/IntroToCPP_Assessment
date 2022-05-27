#include "Bullet.h"
#include "SceneObject.h"
#include "raylib.h"

//Constructors
Bullet::Bullet() 
{ 
    //variables initialized as a default value
    timer = 0;
    Destroyed = false;
    Velocity = { 0,0 };
    Sprite = LoadTexture("Assets/Bullet.png");
}
Bullet::Bullet(Vector2 position, Vector2 velocity, float rotation, Texture2D sprite) : SceneObject(position, velocity, 40, 0, 0.2f)
{
    //variables initialized based on their input
    Position = position;
    Velocity = velocity;
    Rotation = rotation;
    Sprite = sprite;
    timer = 0;
    Destroyed = false;

}


//Update function called every frame if the object is not destroyed
void Bullet::Update(float deltaTime)
{
    if (Destroyed == false) {
        //timer is increased every second
        timer += deltaTime;

        float r = (Rotation - 90) / 180 * PI;
        //Position is increased in direction every frame
        Velocity = { (cos(r)) * speed, sin(r) * speed};
        Position.x += Velocity.x * deltaTime;
        Position.y += Velocity.y * deltaTime;
    }
    //if the bullet has been running for longer than its life time it will be destroyed
    if (timer > lifeTime)
        Destroyed = true;

}


//called every frame to draw the sprite at the objects current position
//as well as its collider if the object is not destroyed
//draws sprite at an offset because raylib draws from top left corner
void Bullet::Draw() 
{
    if (Destroyed == false) {
        DrawCircleLines((int)Position.x, (int)Position.y, Radius * Scale, YELLOW);
        Rectangle sourceRect = { 0,0,(float)Sprite.width, (float)Sprite.height };
        Rectangle distRect = { Position.x, Position.y, Sprite.width * Scale, Sprite.height * Scale };
        DrawTexturePro(Sprite, sourceRect, distRect, { Sprite.width / 2 * Scale, Sprite.height / 2 * Scale }, Rotation, WHITE);
    }
}
