#pragma once
#include <SFML/Graphics.hpp>

#include <systeme/Systeme.h>

namespace ez
{
	class GameObject;

	class Component
	{
	protected:
		GameObject& m_owner;

	public:
		Component(GameObject& owner);
		virtual ~Component() = default;
		
		virtual void Update(float dt, systeme::Systeme& m_systeme);
		virtual void Render(sf::RenderWindow& m_window);
	};
}