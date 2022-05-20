#pragma once
#include <vector>
#include <iostream>
#include<raylib.h>
using namespace std;

class SceneObject
{
public:
		SceneObject() {};


		vector<SceneObject> children;
		SceneObject* parent = nullptr;
		//SceneObject& parentRef = parent;

		float xPos = 0;
		float yPos = 0;

		vector<float*> globalTransform = { &xPos, &yPos };
		vector<float>localTransform;

		//SceneObject Parent() { {return parent; } }



		virtual void Update(float deltaTime) {
			OnUpdate(deltaTime);

			for (SceneObject child : children)
			{
				child.Update(deltaTime);
			}
		}

		void Draw() {
			OnDraw();

			for (SceneObject child : children)
			{
				child.Draw();
			}
		}

		virtual void OnUpdate(float deltaTime) {

		}
		virtual void OnDraw() {}

		void UpdateTransform() {

		}
};

