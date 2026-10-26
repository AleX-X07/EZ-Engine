#include "movement.h"

#include <SFML/Graphics.hpp>

#include<Systeme.h>

Movement::Movement(GameObject* owner, float y_speed) : Component(owner), m_speed(y_speed)
{
}

void Movement::Update(float dt, Systeme* m_systeme)
{
	auto& m_vecowner = owner->GetTransform();

	sf::Vector2f m_vec = { 0,0 };
	int dirX = 0;
	int dirY = 0;

	// X
	if (m_systeme->m_input->IsKeyHeld(sf::Keyboard::Key::Q))
	{
		dirX = -1;
	}
	else if (m_systeme->m_input->IsKeyHeld(sf::Keyboard::Key::D))
	{
		dirX = 1;
	}
	if (dirX != 0)
	{
		m_vec.x = dt * m_speed * dirX;
	}

	// Y
	if (m_systeme->m_input->IsKeyHeld(sf::Keyboard::Key::Z))
	{
		dirY = -1;
	}
	else if (m_systeme->m_input->IsKeyHeld(sf::Keyboard::Key::S))
	{
		dirY = 1;
	}
	if (dirY != 0)
	{
		m_vec.y = dt * m_speed * dirY;
	}

	m_vecowner += m_vec;
}
