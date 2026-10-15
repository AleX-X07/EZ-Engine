#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <Systeme.h>

class GameScene;

class Loop
{
private:
	bool run = true;

	sf::RenderWindow* m_window;

	sf::Clock m_clock;
	float dt = 0.0f;

	Systeme* m_systeme;

	void UpdateEvent();
	void UpdateTime();
	void Update(float dt);
	void Render(sf::RenderWindow* window);

public:
	Loop();
	~Loop();

	void Run();
};
