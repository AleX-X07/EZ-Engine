#pragma once

#include <SFML/Graphics.hpp>

#include <systeme/Systeme.h>
#include <ez/Game.h>

class GameScene;

class MainLoop
{
private:
	bool run = true;

	sf::Clock m_clock;
	float dt = 0.0f;
	sf::Time delatTime;

	systeme::Systeme m_systeme;
	ez::Game& m_game;

	sf::RenderWindow& m_window;

private:
	MainLoop(sf::RenderWindow& window, ez::Game& game);
	~MainLoop();

	void UpdateEvent();
	void UpdateTime();
	void Update();
	void Render();

public:
	void Loop();

	template<typename T> 
	static void Run(const std::string& name)
	{
		sf::RenderWindow m_window(sf::VideoMode({1280,720}),name);
		T game(m_window);
		MainLoop loop(m_window,game);
		loop.Loop();
	}
};

