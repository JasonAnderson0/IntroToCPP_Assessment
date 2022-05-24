#pragma once
#include "SceneObject.h"
#include "raylib.h"

class Paddle :
    public SceneObject
{
public:
    int playerNumb;
    Paddle();
    Paddle(Vector2 position, Vector2 size,float speed, int playernumb);

    void Update(float deltaTime) override;
    void Draw() override;

private:
    //Collision stuff

};

