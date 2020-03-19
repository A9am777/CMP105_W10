#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
class Player :
public GameObject
{
	public:
		Player();
		~Player();

		void update(float) override;
		void collisionResponse(GameObject*) override;
		void handleInput(float) override;
		bool collides(GameObject*);
	private:

};

