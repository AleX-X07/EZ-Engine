#pragma once

#include <SFML/Graphics.hpp>

#include <Systeme.h>
#include <Game.h>

class GameScene;

class Loop
{
private:
	bool run = true;

	sf::RenderWindow* m_window;

	sf::Clock m_clock;
	float dt = 0.0f;

	Systeme* m_systeme;
	Game* m_game;

	void UpdateEvent();
	void UpdateTime();
	void Update();
	void Render();

public:
	Loop(std::string name);
	~Loop();

	void SetGame(Game* newGame);

	void Run();
};
