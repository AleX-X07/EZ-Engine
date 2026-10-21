#include <RenderComp.h>
#include <GameObject.h>

RenderComp::RenderComp(GameObject* owner) : Component(owner), m_texture(nullptr), m_color({0,0,0})
{
	auto pos = owner->GetTransform();
	auto size = owner->GetSize();

	m_rect.setSize(size);
	m_rect.setOrigin(size/2.0f);
	m_rect.setPosition(pos);

	m_rect.setFillColor(m_color);
}

void RenderComp::SetTexture(std::string path)
{
	m_texture = new sf::Texture();

	if (!m_texture->loadFromFile(path))
	{
		m_texture = nullptr;
		m_rect.setTexture(m_texture);
	}
}

void RenderComp::SetColor(sf::Color color)
{
	m_color = color;
	m_rect.setFillColor(m_color);
}

void RenderComp::Update(float dt, Systeme* m_systeme)
{
	auto pos = owner->GetTransform();
	auto size = owner->GetSize();
	m_rect.setPosition(pos);
	m_rect.setSize(size);
}

void RenderComp::Render(sf::RenderWindow* m_window)
{
	m_window->draw(m_rect);
}
