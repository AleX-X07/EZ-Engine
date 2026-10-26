#include "Game.h"

Game::Game() : current_scene(nullptr), m_window(nullptr)
{
}

Game::~Game()
{
	for (auto& scn : myScenes)
	{
		delete scn;
		scn = nullptr;
	}
	myScenes.clear();
	current_scene = nullptr;
}

void Game::SetWindow(sf::RenderWindow* y_window)
{
	m_window = y_window;
}

void Game::AddScene(std::string name)
{
	GameScene* newScene = new GameScene(name);
	myScenes.push_back(newScene);
	SetCurrentScene(name);
}

void Game::SetCurrentScene(std::string name)
{
	for (auto& scn : myScenes)
	{
		if (scn->GetName() == name)
		{
			current_scene = scn;
		}
	}
}

void Game::Init()
{

}

void Game::Update(float dt, Systeme* m_systeme)
{
	if (current_scene != nullptr)
	{
		current_scene->Update(dt, m_systeme);
	}
}

void Game::Render(sf::RenderWindow* y_window)
{
	if (current_scene != nullptr)
	{
		current_scene->Render(y_window);
	}
}

GameScene* Game::GetScene(std::string name)
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

sf::RenderWindow* Game::GetWindow()
{
	return m_window;
}
