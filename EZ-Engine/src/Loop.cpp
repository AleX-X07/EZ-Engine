#include <Loop.h>

Loop::Loop(std::string name)
{
	m_window = new sf::RenderWindow(sf::VideoMode({ 1280,720 }), name);
	m_systeme = new Systeme();
	m_game = nullptr;
}

Loop::~Loop()
{
	delete m_window;
	delete m_systeme;

	m_window = nullptr;
	m_systeme = nullptr;
}

void Loop::SetGame(Game* newGame)
{
	m_game = newGame;
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

void Loop::Update()
{
	if (m_game != nullptr)
	{
		m_game->Update(dt, m_systeme);
	}
}

void Loop::Render()
{
	if (m_game != nullptr)
	{
		m_game->Render(m_window);
	}
}

void Loop::Run()
{
	m_game->Init();
	while (run)
	{
		UpdateEvent();
		UpdateTime();
		Update();
		m_window->clear();
		Render();
		m_window->display();
	}
}
