#include "SceneObject.h"
#include "raylib.h"


class Ship : public SceneObject
{
public: 
	float turnSpeed;
	float speed;
	Texture2D bulletSprite;
	

	Ship(Vector2 position, Texture2D sprite) 
	{
	}

	
	 void Update(float deltaTime) override 
	 {}
};