#pragma once
#include <SFML/Graphics.hpp>

class GameObject;
class Systeme;

class Component 
{
protected:
	GameObject* owner;

public:
	Component(GameObject* _owner);
	virtual ~Component() = default;

	virtual void Update(float dt, Systeme* m_systeme);
	virtual void Render(sf::RenderWindow* m_window);
};