#include "mainloop.h"

#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>

MainLoop::MainLoop(sf::RenderWindow& window, ez::Game& game)
	: m_window(window), m_game(game)
{
}

MainLoop::~MainLoop()
{
	ImGui::SFML::Shutdown();
}

void MainLoop::UpdateEvent()
{
	m_systeme.m_input.Reset();
	while (const std::optional event = m_window.pollEvent())
	{
		m_systeme.m_input.SetEvent(*event);
		ImGui::SFML::ProcessEvent(m_window, *event);
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
	delatTime = sf::seconds(dt);
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
	ImGui::SFML::Init(m_window);	
	m_clock.restart();
	while (run)
	{
		UpdateEvent();
		UpdateTime();
		ImGui::SFML::Update(m_window, delatTime);
		Update();

		m_window.clear();
		Render();
		ImGui::SFML::Render(m_window);
		m_window.display();
	}
}