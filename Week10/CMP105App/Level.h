#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Framework/TileMap.h"
#include "Player.h"

#define tileSiz 30
#define tileTexSiz 16

class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	TileMap map;
	std::vector<GameObject> tiles;
	sf::Vector2u tileDim;
	Player player;
};