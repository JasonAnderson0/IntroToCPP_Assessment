#include "Game.h"
#include <raylib.h>

int main()
{
    Game game;
    int windowWidth = 800;
    int windowHeight = 800;

    InitWindow(windowWidth, windowHeight, "Game");
    SetTargetFPS(60);

    game.Load();

    while (!WindowShouldClose()) {
        game.Update(GetFrameTime());
        game.Draw();
    }
    //game.Unload();
}


    //Image LoadImageEx(Color * pixels, int width, int height)
    //{
    //    Image image = { 0 };
    //    unsigned char* fileData = (unsigned char*)pixels;
    //    unsigned char* dataPtr = fileData;
    //    unsigned int size = GetPixelDataSize(width, height, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    //    image.data = RL_MALLOC(size);      // Allocate required memory in bytes
    //    if (image.data)
    //    {
    //        memcpy(image.data, dataPtr, size); // Copy required data to image
    //        image.width = width;
    //        image.height = height;
    //        image.mipmaps = 1;
    //        image.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
    //    }
    //    return image;
    //}

    //Color* GetImageData(Image image)
    //{
    //    return (Color*)image.data;
    //}