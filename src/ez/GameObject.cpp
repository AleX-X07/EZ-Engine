#include "ez/GameObject.h"

#include <systeme/Systeme.h>

#include <ez/GameScene.h>


ez::GameObject::GameObject(GameScene& current_scene, const std::string& name) : m_name(name), m_transform({ 0,0 }), m_size({ 50,50 }), m_current_scene(current_scene)
{
}

ez::GameObject::~GameObject()
{
	for (auto& comp : m_components)
	{
		delete comp;
		comp = nullptr;
	}
}

void ez::GameObject::Update(float dt, systeme::Systeme& m_systeme)
{
	for (auto& comp : m_components)
	{
		if (comp)
		{
			comp->Update(dt, m_systeme);
		}
	}
}

void ez::GameObject::Render(sf::RenderWindow& m_window)
{
	for (auto& comp : m_components)
	{
		if (comp)
		{
			comp->Render(m_window);
		}
	}
}

const std::string& ez::GameObject::GetName() const
{
	return m_name;
}

maths::TVecteur2<float>& ez::GameObject::GetTransform()
{
	return m_transform;
}

maths::TVecteur2<float>& ez::GameObject::GetSize()
{
	return m_size;
}