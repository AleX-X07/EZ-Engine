#include <RenderComp.h>
#include <GameObject.h>

RenderComp::RenderComp(GameObject* owner) : Component(owner), m_texture(nullptr), m_color({255,255,255,255})
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

	bool load = m_texture->loadFromFile(path);

	if (!load)
	{
		delete m_texture;
		m_texture = nullptr;
	}
	else 
	{
		m_rect.setFillColor({255,255,255,255});
		m_rect.setTexture(m_texture);
	}
}

void RenderComp::SetColor(sf::Color color)
{
	m_color = color;
	m_rect.setFillColor(m_color);
}

sf::Texture* RenderComp::GetTexture()
{
	return m_texture;
}

sf::Color& RenderComp::GetColor()
{
	return m_color;
}

sf::RectangleShape& RenderComp::GetRect()
{
	return m_rect;
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
