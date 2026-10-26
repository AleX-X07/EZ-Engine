#include <GameScene.h>

#include <Systeme.h>

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
	myObjects.clear();
}

void GameScene::ChangeDefaultLayer(unsigned int m_layer)
{
	m_default_layer = m_layer;
}

void GameScene::AddObject(std::string name)
{
	GameObject* newObjt = new GameObject(name);
	myObjects.push_back(newObjt);
	layer[m_default_layer].push_back(newObjt);
}

void GameScene::SetLayer(unsigned int emplace, GameObject* obj)
{
	layer[emplace].push_back(obj);
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
	if (!layer.empty())
	{
		for (auto& l : layer)
		{
			if (!l.empty())
			{
				for (auto& obj : l)
				{
					obj->Render(m_window);
				}
			}
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
