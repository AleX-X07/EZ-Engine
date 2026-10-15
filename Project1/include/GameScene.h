#pragma once
#include <SFML/Graphics.hpp>

class Systeme;

class GameScene
{
private:

public:
	GameScene();
	~GameScene();

	void Update(float dt, Systeme* m_systeme);
	void Render(sf::RenderWindow* m_window);
};
