#include <Input.h>

void Input::SetEvent(const sf::Event& m_event)
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

void Input::Reset()
{
	m_keypressed = false;
	m_mousepressed = false;
}

bool Input::IsKeyPressed(sf::Keyboard::Key y_key)
{
	return m_keypressed && m_key == y_key;
}

bool Input::IsMousePressed(sf::Mouse::Button y_mouse)
{
	return m_mousepressed && m_mouse == y_mouse;
}

bool Input::IsKeyHeld(sf::Keyboard::Key y_key)
{
	return sf::Keyboard::isKeyPressed(y_key);
}

bool Input::IsMouseHeld(sf::Mouse::Button y_mouse)
{
	return m_mouse == y_mouse;
}

sf::Vector2i& Input::GetMousePos()
{
	return m_mousepos;
}


