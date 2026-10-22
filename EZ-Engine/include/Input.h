#pragma once
#include <SFML/Graphics.hpp>

class Input
{
private:

	bool m_keypressed = false;
	bool m_mousepressed = false;

	sf::Vector2i m_mousepos = { 0,0 };

	sf::Keyboard::Key m_key;
	sf::Mouse::Button m_mouse;

public:
	Input() = default;
	~Input() = default;

	void SetEvent(const sf::Event& m_event);
	void Reset();

	bool IsKeyPressed(sf::Keyboard::Key y_key);
	bool IsMousePressed(sf::Mouse::Button y_mouse);

	bool IsKeyHeld(sf::Keyboard::Key y_key);
	bool IsMouseHeld(sf::Mouse::Button y_mouse);

	sf::Vector2i& GetMousePos();
};