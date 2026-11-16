#pragma once
#include <SFML/Graphics.hpp>

#include <ez/Component.h>

namespace ez::components::graphics
{
	class Camera : public Component
	{
	private:
		sf::View m_view;

		GameObject* m_target;
		bool haveTarget = false;

	public:
		Camera(GameObject* owner);
		~Camera() = default;

		void SetCamera(const sf::Vector2f& size);
		void SetTarget(GameObject* target);

		virtual void Update(float dt, systeme::Systeme& systeme) override;
		virtual void Render(sf::RenderWindow& m_window) override;
	};
}