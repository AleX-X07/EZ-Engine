#pragma once
#include <SFML/Graphics.hpp>

#include <GameObject.h>

class Systeme;

class GameScene
{
private:
	std::string name;

	std::vector<GameObject*> myObjects;

public:
	GameScene(std::string _name);
	~GameScene();

	void AddObject(std::string name);

	void Update(float dt, Systeme* m_systeme);
	void Render(sf::RenderWindow* m_window);

	GameObject* GetObject(std::string name);
	std::string& GetName();
};
