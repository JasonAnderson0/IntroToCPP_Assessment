#include "raylib.h"
#include "DataFile.h"

int main(int argc, char* argv[])
{
    //initiallises all the raylib variables for the window
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    //creates a datafile and begins loading the first file
    DataFile data;
    int currentRecordIdx = 0;

    data.Load("npc_data.dat", currentRecordIdx);

    DataFile::Record* currentRecord = data.GetRecord();
    Texture2D recordTexture = LoadTextureFromImage(currentRecord->image);


    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        //if the left arrow key is pressed it and it is not at the first record
        //it will set the current record id to 1 less than it currently is
        //and then load all the information from the record id
        if (IsKeyPressed(KEY_LEFT))
        {
            if (currentRecordIdx != 0) {
                currentRecordIdx--;
                if (currentRecordIdx < 0)
                {
                    currentRecordIdx = 0;
                }
                data.Load("npc_data.dat", currentRecordIdx);
                currentRecord = data.GetRecord();
                recordTexture = LoadTextureFromImage(currentRecord->image);
            }
        }

        //if the right arrow key is pressed it and it is not at the last record
        //it will set the current record id to 1 more than it currently is
        //and then load all the information from the record id

        if (IsKeyPressed(KEY_RIGHT))
        {
            if (currentRecordIdx != 4)
            {
                currentRecordIdx++;
                if (currentRecordIdx >= data.GetRecordCount())
                {
                    currentRecordIdx = data.GetRecordCount();
                }
                data.Load("npc_data.dat", currentRecordIdx);
                currentRecord = data.GetRecord();
                recordTexture = LoadTextureFromImage(currentRecord->image);
            }
        }

        //this will begin drawing all the information onto the screen
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(recordTexture, 300, 50, WHITE);

        DrawText("NAME", 10, 50, 20, LIGHTGRAY);
        DrawText(currentRecord->name.c_str(), 10, 80, 20, LIGHTGRAY);

        DrawText("AGE", 10, 120, 20, LIGHTGRAY);
        DrawText(to_string(currentRecord->age).c_str(), 10, 150, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow(); 

    return 0;
}