#include "Asteroid.h"
#include "SceneObject.h"
#include "raylib.h"
#include "Ship.h"
#include "Bullet.h"

//Constructors
Asteroid::Asteroid() 
{
    //variables initialized as a default value
    //will intialize direction (velocity) and position to random values
    float Velx = (float)(rand() % 100 - 50);
    Velocity = { Velx , Velx};
    float Posx = (float)(rand() % GetScreenWidth()); float Posy = (float)(rand() % GetScreenWidth());
    //if asteroid would spawn at the ships starting location it will be moved
    //to prevent the player losing before they can start
    if (Posx < 500 && Posx > 400 && Posy > 400 && Posy > 400){
        Posx -= 100;
        Posy -= 100;
    }
    Position = { Posx , Posy };
    Sprite = LoadTexture("Assets/Asteroid.png");
    Scale = (float)(rand() % 3);
    Speed = (float)(rand() & 20 - 10);
    Radius = 20;
}
Asteroid::Asteroid(Vector2 position, Vector2 velocity, float scale, Texture2D sprite, float speed) : SceneObject(position, velocity, 40, 90, 1)
{
    //variables initialized based on their input
    Position = position;
    Velocity = velocity;
    Sprite = sprite;
    Scale = scale;
    Speed = speed;
};


//Update function called every frame if the object is not destroyed
void Asteroid::Update(float deltaTime) 
{
    //will constantly move the asteroid based on the random direciton its assigned
    Position.x += Velocity.x * Speed * deltaTime;
    Position.y += Velocity.y * deltaTime;

    //will allow asteroids to wrap around the screen if they move too far instead of getting lost
    float w = (float)GetScreenWidth();
    float h = (float) GetScreenHeight();

    Vector2 p = Position;
    if (Position.x < -Radius) p.x = w + Radius;
    if (Position.y < -Radius) p.y = w + Radius;
    if (Position.x > w + Radius) p.x = -Radius;
    if (Position.y > w + Radius) p.y = -Radius;

    Position = p;
}


//is called when needing to check if the ship is colliding with an asteroid
bool Asteroid::CheckCollision(Ship other) 
{
float obstx = (Position.x - other.Position.x);
float obsty = (Position.y - other.Position.y);
float obstdist = obstx * obstx + obsty * obsty;
float rads = Radius + other.Radius;

return(obstdist < rads* rads);
}
//is called when needing to check if a bullet is colliding with an asteroid
bool Asteroid::CheckCollision(Bullet other) {
    float obstx = (Position.x - other.Position.x);
    float obsty = (Position.y - other.Position.y);
    float obstdist = obstx * obstx + obsty * obsty;
    float rads = Radius + other.Radius;

    return(obstdist < rads * rads);
}

//called every frame to draw the sprite at the objects current position
//as well as its collider if the object is not destroyed
//draws sprite at an offset because raylib draws from top left corner
void Asteroid::Draw() 
{
    if (Destroyed == false) 
    {
        Rectangle sourceRect = { 0,0,(float)Sprite.width, (float)Sprite.height };
        Rectangle distRect = { Position.x, Position.y, Sprite.width * Scale, Sprite.height * Scale };
        DrawTexturePro(Sprite, sourceRect, distRect, { Sprite.width / 2 * Scale, Sprite.height / 2 * Scale }, Rotation, WHITE);
        DrawCircleLines((int)Position.x, (int)Position.y, Radius * Scale, YELLOW);
    }
}
