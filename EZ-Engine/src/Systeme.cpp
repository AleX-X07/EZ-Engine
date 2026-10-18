#include <Systeme.h>

Systeme::Systeme()
{
	m_input = new Input();
}

Systeme::~Systeme()
{
	delete m_input;

	m_input = nullptr;
}
