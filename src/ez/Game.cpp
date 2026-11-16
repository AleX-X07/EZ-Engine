#include "ez/Game.h"

ez::Game::Game(sf::RenderWindow& window) : current_scene(nullptr), m_window(window)
{
}

ez::Game::~Game()
{
	for (auto& scn : myScenes)
	{
		delete scn;
		scn = nullptr;
	}
	myScenes.clear();
	current_scene = nullptr;
}

ez::GameScene* ez::Game::AddScene(const std::string& name)
{
	GameScene* newScene = new GameScene(name);
	myScenes.push_back(newScene);
	SetCurrentScene(name);
	return newScene;
}

void ez::Game::SetCurrentScene(const std::string& name)
{
	for (auto& scn : myScenes)
	{
		if (scn->GetName() == name)
		{
			current_scene = scn;
		}
	}
}

void ez::Game::Init()
{

}

void ez::Game::Update(float dt, systeme::Systeme& m_systeme)
{
	if (current_scene != nullptr)
	{
		current_scene->Update(dt, m_systeme);
	}
}

void ez::Game::Render(sf::RenderWindow& m_window)
{
	if (current_scene != nullptr)
	{
		current_scene->Render(m_window);
	}
}

ez::GameScene* ez::Game::GetScene(const std::string& name)
{
	for (auto& scn : myScenes)
	{
		if (scn->GetName() == name)
		{
			return scn;
		}
	}
	return nullptr;
}

sf::RenderWindow& ez::Game::GetWindow()
{
	return m_window;
}
