#include <Loop.h>

#include <GameScene.h>

Loop::Loop()
{
	m_window = new sf::RenderWindow(sf::VideoMode({ 1280,720 }), "MyGame");
	m_systeme = new Systeme();
}

Loop::~Loop()
{
	delete m_window;
	delete m_systeme;

	m_window = nullptr;
	m_systeme = nullptr;
}

void Loop::UpdateEvent()
{
	while (const std::optional event = m_window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			m_window->close();
		}
	}
}

void Loop::UpdateTime()
{
	sf::Time elasped = m_clock.getElapsedTime();
	m_clock.restart();
	dt = elasped.asSeconds();
}

void Loop::Update(float dt)
{
	auto m_gamescene = m_systeme->m_gamescene;

	if (m_gamescene)
	{
		m_gamescene->Update(dt, m_systeme);
	}
}

void Loop::Render(sf::RenderWindow* window)
{
	auto m_gamescene = m_systeme->m_gamescene;

	if (m_gamescene)
	{
		m_gamescene->Render(window);
	}
}

void Loop::Run()
{
	while (run)
	{
		UpdateEvent();
		UpdateTime();
		Update(dt);
		m_window->clear();
		Render(m_window);
		m_window->display();
	}
}
