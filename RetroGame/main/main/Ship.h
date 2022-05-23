#include "SceneObject.h"
#include "raylib.h"


class Ship : public SceneObject
{
public: 
	float turnSpeed = 180;
	float speed = 100;
	Texture2D bulletSprite;
	

	Ship(Vector2 position, Texture2D sprite) 
	{
		bulletSprite = LoadTexture("Assets/Bullet.png");
		
	}

	
	 void Update(float deltaTime) override 
	 {
		 SceneObject::Update(deltaTime);
		if (IsKeyDown(KEY_RIGHT));
		if (IsKeyDown(KEY_LEFT));
	}
};