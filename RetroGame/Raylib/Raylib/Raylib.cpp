#include <iostream>
#include "raylib.h"
#include "Game.h"

int main()
{
    Game game;
    int windowHeight = 800;
    int windowWidth = 800;

    InitWindow(windowWidth, windowHeight, "Game");
    SetTargetFPS(60);

    game.Load();
    while (!WindowShouldClose()) 
    {
        game.Update(GetFrameTime());
        game.Draw();
    }
}
