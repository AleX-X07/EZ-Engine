#include <GameScene.h>

#include <Systeme.h>
#include <RenderComp.h>

#include <map>

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

void GameScene::AddObject(std::string name)
{
	GameObject* newObjt = new GameObject(name);
	myObjects.push_back(newObjt);
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
	std::map<int, std::vector<GameObject*>> m_render;

	for (auto* obj : myObjects)
	{
		if (auto* comp = obj->GetComponent<RenderComp>())
		{
			m_render[comp->GetOrder()].push_back(obj);
		}
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
