#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	map.loadTexture("gfx/marioTiles.png");
	tileDim = sf::Vector2u(6,3);
	std::vector<int> tileMap =
	{
		0, 1, 2, 2, 3, 3,
		0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0
	};
	map.setTileMap(tileMap, tileDim);
	for (int i = 0; i < 12; i++)
	{
		for (int i2 = 0; i2 < 6; i2++)
		{
			GameObject newTile;
			newTile.setSize(sf::Vector2f(tileSiz, tileSiz));
			newTile.setCollider(true);
			newTile.setCollisionBox(sf::FloatRect(0, 0, tileSiz, tileSiz));
			newTile.setTextureRect(sf::IntRect(i * (1+tileTexSiz),i2 * (1+tileTexSiz), tileTexSiz, tileTexSiz));
			tiles.push_back(newTile);
		}
	}
	map.setTileSet(tiles);
	map.setPosition(sf::Vector2f(0,500));
	map.buildLevel();

	player.setInput(input);
	player.setSize(sf::Vector2f(100, 100));
	player.setCollisionBox(sf::FloatRect(0, 0, 100, 100));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
	for (std::vector<GameObject>::const_iterator i = map.getLevel()->begin();i<map.getLevel()->end();i++)
	{
		player.collides(i._Ptr);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	map.render(window);
	window->draw(player);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}