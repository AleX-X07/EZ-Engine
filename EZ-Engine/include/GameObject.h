#pragma once
#include <SFML/Graphics.hpp>

class Systeme;

class GameObject
{
private:
	std::string name = "";
	sf::Vector2f Transform;

public:
	GameObject(std::string _name);
	~GameObject();

	void Update(float dt, Systeme* m_systeme);
	void Render(sf::RenderWindow* m_window);

	std::string& GetName();
	sf::Vector2f& GetTransform();
};