#include "Game.h"
#include <raylib.h>

int main()
{
    //application size set on initial start up
    int windowWidth = 800;
    int windowHeight = 800;

    InitWindow(windowWidth, windowHeight, "Game");

    SetTargetFPS(60);
    Game game;

    game.Load();
    //while the application is running, update and draw will be called from the game
    while (!WindowShouldClose()) {
        game.Update(GetFrameTime());
        game.Draw();
    }
}