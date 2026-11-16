#include "mainloop.h"

MainLoop::MainLoop(const std::string& name) 
	: m_window(sf::VideoMode({ 1280,720 }), name), m_game(nullptr)
{
}

void MainLoop::UpdateEvent()
{
	m_systeme.m_input.Reset();
	while (const std::optional event = m_window.pollEvent())
	{
		m_systeme.m_input.SetEvent(*event);
		if (event->is<sf::Event::Closed>())
		{
			m_window.close();
		}
	}
}

void MainLoop::UpdateTime()
{
	sf::Time elasped = m_clock.getElapsedTime();
	m_clock.restart();
	dt = elasped.asSeconds();
}

void MainLoop::Update()
{
	m_game->Update(dt, m_systeme);	
}

void MainLoop::Render()
{
	m_game->Render(m_window);	
}

void MainLoop::SetGame(ez::Game& newgame)
{
	m_game = &newgame;
}

void MainLoop::Run()
{
	m_game->Init();
	while (run)
	{
		UpdateEvent();
		UpdateTime();
		Update();
		m_window.clear();
		Render();
		m_window.display();
	}
}

MainLoop* MainLoop::Instance(const std::string& name)
{
	if (m_instance == nullptr)
	{
		m_instance = new MainLoop(name);
	}
	return m_instance;
}
