#pragma once
#include "SceneObject.h"
#include "raylib.h"
class Asteroid :
    public SceneObject
{
public:
    Asteroid(Vector2 position, float scale, Texture2D sprite) 
    {
        Scale = scale;
    };


    void OnCollision(SceneObject other) override {
        //if (other is Bullet || other is Ship) {
        //    //stop drawing
        //}
    }

};

