#include "ez/GameScene.h"

#include <systeme/Systeme.h>
#include <ez/components/graphics/renderer.h>


ez::GameScene::GameScene(const std::string& name) : m_name(name)
{
}

ez::GameScene::~GameScene()
{
	for (auto& obj : m_objects)
	{
		delete obj;
		obj = nullptr;
	}
	m_objects.clear();
}

ez::GameObject* ez::GameScene::AddObject(const std::string& name)
{
	GameObject* n_obj = new GameObject(*this, name);
	m_objects.push_back(n_obj);
	return n_obj;
}

void ez::GameScene::Update(float dt, systeme::Systeme& m_systeme)
{
	if (!m_objects.empty())
	{
		for (auto& obj : m_objects)
		{
			obj->Update(dt, m_systeme);
		}
	}
}

void ez::GameScene::Render(sf::RenderWindow& m_window)
{
	if (!sort)
	{
		for (auto* obj : m_objects)
		{
			if (auto* comp = obj->GetComponent<ez::components::graphics::Renderer>())
			{
				m_render[comp->GetOrder()].push_back(obj);
			}
		}
		sort = true;
	}
	for (auto& [order, comps] : m_render)
	{
		for (auto* comp : comps)
		{
			comp->Render(m_window);
		}
	}
}

ez::GameObject* ez::GameScene::GetObject(const std::string& name)
{
	if (!m_objects.empty())
	{
		for (auto& obj : m_objects)
		{
			if (obj->GetName() == name)
			{
				return obj;
			}
		}
	}
}

const std::string& ez::GameScene::GetName() const
{
	return m_name;
}

std::vector<ez::GameObject*>& ez::GameScene::GetListObject()
{
	return m_objects;
}
