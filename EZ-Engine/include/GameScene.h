#pragma once
#include <SFML/Graphics.hpp>

#include <GameObject.h>

class Systeme;

class GameScene
{
private:
	std::string name;

	std::vector<GameObject*> myObjects;

	// Gestion layer
	unsigned int m_default_layer = 0;
	std::vector<std::vector<GameObject*>> layer;

public:
	GameScene(std::string _name);
	~GameScene();

	void ChangeDefaultLayer(unsigned int m_layer);

	void AddObject(std::string name);
	void SetLayer(unsigned int emplace, GameObject* obj);

	void Update(float dt, Systeme* m_systeme);
	void Render(sf::RenderWindow* m_window);

	GameObject* GetObject(std::string name);
	std::string& GetName();
};
