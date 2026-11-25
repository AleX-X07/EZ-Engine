#include "mainloop.h"

MainLoop::MainLoop(sf::RenderWindow& window, ez::Game& game)
	: m_window(window), m_game(game)
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
	m_game.Update(dt, m_systeme);	
}

void MainLoop::Render()
{
	m_game.Render(m_window);	
}

void MainLoop::Loop()
{
	m_game.Init();
	m_clock.restart();
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