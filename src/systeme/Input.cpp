#include "systeme/Input.h"

void systeme::Input::SetEvent(const sf::Event& m_event)
{
	if (const auto* k = m_event.getIf<sf::Event::KeyPressed>())
	{
		m_key = k->code;
		m_keypressed = true;
	}
	else if (const auto* m = m_event.getIf<sf::Event::MouseButtonPressed>())
	{
		m_mousepressed = true;
		m_mouse = m->button;
		m_mousepos = m->position;
	}
}

void systeme::Input::Reset()
{
	m_keypressed = false;
	m_mousepressed = false;
}

bool systeme::Input::IsKeyPressed(const sf::Keyboard::Key& key)
{
	return m_keypressed && m_key == key;
}

bool systeme::Input::IsMousePressed(const sf::Mouse::Button& mouse)
{
	return m_mousepressed && m_mouse == mouse;
}

bool systeme::Input::IsKeyHeld(const sf::Keyboard::Key& key)
{
	return sf::Keyboard::isKeyPressed(key);
}

bool systeme::Input::IsMouseHeld(const sf::Mouse::Button& mouse)
{
	return m_mouse == mouse;
}

sf::Vector2i& systeme::Input::GetMousePos()
{
	return m_mousepos;
}


