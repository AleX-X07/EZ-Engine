#include "GameObject.h"

GameObject::GameObject(std::string _name) : name(_name), Transform({0,0}), Size({50,50})
{
}

GameObject::~GameObject()
{
	for (auto& comp : myComponent)
	{
		delete comp;
		comp = nullptr;
	}
}

void GameObject::Update(float dt, Systeme* m_systeme)
{
	for (auto& comp : myComponent)
	{
		if (comp)
		{
			comp->Update(dt, m_systeme);
		}
	}
}

void GameObject::Render(sf::RenderWindow* m_window)
{
	for (auto& comp : myComponent)
	{
		if (comp)
		{
			comp->Render(m_window);
		}
	}
}

std::string& GameObject::GetName()
{
	return name;
}

sf::Vector2f& GameObject::GetTransform()
{
	return Transform;
}

sf::Vector2f& GameObject::GetSize()
{
	return Size;
}
