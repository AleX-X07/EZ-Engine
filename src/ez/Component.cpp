#include "ez/Component.h"

ez::Component::Component(GameObject& owner) : m_owner(owner)
{
}

void ez::Component::Update(float dt, systeme::Systeme& m_systeme)
{
}

void ez::Component::Render(sf::RenderWindow& m_window)
{
}
