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

	systeme::Systeme m_systeme;
	ez::Game m_game;

public:
	sf::RenderWindow m_window;

private:
	MainLoop(const std::string& name);
	~MainLoop() = default;

	void UpdateEvent();
	void UpdateTime();
	void Update();
	void Render();

public:
	void SetGame(ez::Game& newgame);
	void Run();

	static MainLoop* Instance(const std::string& name);
};

