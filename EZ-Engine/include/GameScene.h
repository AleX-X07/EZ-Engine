#pragma once
#include <SFML/Graphics.hpp>

#include <GameObject.h>
#include <map>

class Systeme;

class GameScene
{
private:
	std::string name;

	std::vector<GameObject*> myObjects;

	std::map<int, std::vector<GameObject*>> m_render;
	bool m_render_sorted = false;

public:
	GameScene(std::string _name);
	~GameScene();

	GameObject* AddObject(std::string name);

	void Update(float dt, Systeme* m_systeme);
	void Render(sf::RenderWindow* m_window);

	GameObject* GetObject(std::string name);
	std::string& GetName();
	std::vector<GameObject*>& GetListObject();
};
