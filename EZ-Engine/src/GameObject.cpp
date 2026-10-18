#include "GameObject.h"

GameObject::GameObject(std::string _name) : name(_name), Transform({0,0})
{
}

GameObject::~GameObject()
{
}

void GameObject::Update(float dt, Systeme* m_systeme)
{
}

void GameObject::Render(sf::RenderWindow* m_window)
{
}

std::string& GameObject::GetName()
{
	return name;
}

sf::Vector2f& GameObject::GetTransform()
{
	return Transform;
}
