#include <GameScene.h>

#include <Systeme.h>
#include <RenderComp.h>


GameScene::GameScene(std::string _name) : name(_name)
{
}

GameScene::~GameScene()
{
	for (auto& obj : myObjects)
	{
		delete obj;
		obj = nullptr;
	}
}

GameObject* GameScene::AddObject(std::string name)
{
	GameObject* newObjt = new GameObject(name);
	myObjects.push_back(newObjt);
	return newObjt;
}

void GameScene::Update(float dt, Systeme* m_systeme)
{
	if(!myObjects.empty())
	{
		for (auto& obj : myObjects)
		{
			obj->Update(dt,m_systeme);
		}
	}
}

void GameScene::Render(sf::RenderWindow* m_window)
{
	if (!m_render_sorted)
	{
		for (auto* obj : myObjects)
		{
			if (auto* comp = obj->GetComponent<RenderComp>())
			{
				m_render[comp->GetOrder()].push_back(obj);
			}
		}
		m_render_sorted = true;
	}

	for (auto& [order, comps] : m_render)
	{
		for (auto* comp : comps)
		{
			comp->Render(m_window);
		}
	}
}

GameObject* GameScene::GetObject(std::string name)
{
	if (!myObjects.empty())
	{
		for (auto& obj : myObjects)
		{
			if (obj->GetName() == name)
			{
				return obj;
			}
		}
	}
}

std::string& GameScene::GetName()
{
	return name;
}

std::vector<GameObject*>& GameScene::GetListObject()
{
	return myObjects;
}
