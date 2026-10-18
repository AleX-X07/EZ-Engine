#include <Component.h>
#include <Systeme.h>

Component::Component(GameObject* _owner) : owner(_owner)
{
}

void Component::Update(float dt, Systeme* m_systeme)
{
}

void Component::Render(sf::RenderWindow* m_window)
{
}
