#include <Systeme.h>

Systeme::Systeme()
{
	m_input = new Input();
	m_gamescene = new GameScene();
}

Systeme::~Systeme()
{
	delete m_input;
	delete m_gamescene;

	m_input = nullptr;
	m_gamescene = nullptr;
}
