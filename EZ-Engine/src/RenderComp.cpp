#include <RenderComp.h>
#include <GameObject.h>

RenderComp::RenderComp(GameObject* owner) : Component(owner), m_texture(nullptr), m_color({0,0,0})
{
	auto pos = owner->GetTransform();
	auto size = owner->GetSize();

	m_rect.setPosition(pos);
	m_rect.setSize(size);

}

void RenderComp::Update(float dt, Systeme* m_systeme)
{
}

void RenderComp::Render(sf::RenderWindow* m_window)
{
}
