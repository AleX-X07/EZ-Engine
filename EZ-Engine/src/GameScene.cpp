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
	if (!myObjects.empty())
	{
		for (auto& obj : myObjects)
		{
			obj->Render(m_window);
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
