#include<raylib.h>
#include<iostream>
using namespace std;


class SpriteObject: SceneObject
{
public:

	Texture2D texture;
	float Width() { return texture.width; }
	float Height() { return texture.height; }

	void Load(string filename) 
	{
		Image img = LoadImage(filename);
		texture = LoadTextureFromImage(img);

	}

	void OnDraw() {
		float rotation;

		DrawTextureEx(texture, vect)
	}



};