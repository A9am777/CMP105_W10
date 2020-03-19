#include "Player.h"

Player::Player()
{
	collider = true;
}

Player::~Player()
{

}

void Player::update(float dt)
{
	velocity.y += 98 * dt;
	move(dt * velocity);
}
#include <iostream>
void Player::collisionResponse(GameObject* col)
{
	if (getPosition().y < col->getPosition().y)
	{
		setPosition(getPosition().x, col->getPosition().y - getSize().y);
		velocity.y = 0;
	}
}

void Player::handleInput(float dt)
{
	velocity.x = 0;
	if (input->isKeyDown(sf::Keyboard::A)) { velocity.x = -100; }
	if (input->isKeyDown(sf::Keyboard::D)) { velocity.x = 100; }
}

bool Player::collides(GameObject* obj)
{
	if (obj->isCollider() & isCollider())
	{
		if (Collision::checkBoundingBox(this,obj))
		{
			collisionResponse(obj);
			return true;
		}
	}
	return false;
}
