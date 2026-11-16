#pragma once
#include <SFML/Graphics.hpp>

namespace systeme
{
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

		bool IsKeyPressed(const sf::Keyboard::Key& key);
		bool IsMousePressed(const sf::Mouse::Button& mouse);

		bool IsKeyHeld(const sf::Keyboard::Key& key);
		bool IsMouseHeld(const sf::Mouse::Button& mouse);

		sf::Vector2i& GetMousePos();
	};
}