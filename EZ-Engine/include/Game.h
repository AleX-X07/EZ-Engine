#pragma once
#include <SFML/Graphics.hpp>
#include <GameScene.h>

class Systeme;

class Game
{
private:
	std::vector<GameScene*> myScenes;
	GameScene* current_scene;

	sf::RenderWindow* m_window;

public:
	Game();
	virtual ~Game();

	void SetWindow(sf::RenderWindow* y_window);
	void AddScene(std::string name);
	void SetCurrentScene(std::string name);

	virtual void Init();

	virtual void Update(float dt, Systeme* m_systeme);
	virtual void Render(sf::RenderWindow* y_window);

	GameScene* GetScene(std::string name);
	sf::RenderWindow* GetWindow();
};