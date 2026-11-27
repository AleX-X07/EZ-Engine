#include "ez/components/graphics/Camera.h"

#include <ez/GameObject.h>

ez::components::graphics::Camera::Camera(GameObject* owner) : Component(owner), m_target(nullptr)
{
	sf::Vector2f pos = { m_owner->GetTransform().x, m_owner->GetTransform().y };
	m_view.setCenter(pos);
}

void ez::components::graphics::Camera::SetCamera(const sf::Vector2f& size)
{
	m_view.setSize(size);
}

void ez::components::graphics::Camera::SetTarget(GameObject* target)
{
	m_target = target;
	haveTarget = true;
}

void ez::components::graphics::Camera::Update(float dt, systeme::Systeme& systeme)
{
	if (haveTarget)
	{
		m_owner->GetTransform() = m_target->GetTransform();
	}	
	sf::Vector2f pos = { m_owner->GetTransform().x, m_owner->GetTransform().y };
	m_view.setCenter(pos);
}

void ez::components::graphics::Camera::Render(sf::RenderWindow& m_window)
{
	m_window.setView(m_view);
}
