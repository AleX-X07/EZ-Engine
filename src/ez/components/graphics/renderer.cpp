#include "ez/components/graphics/renderer.h"

#include <ez/GameObject.h>

ez::components::graphics::Renderer::Renderer(GameObject& owner) : Component(owner), m_texture(nullptr), m_color({ 255,255,255,255 })
{
	auto pos = m_owner.GetTransform();
	auto size = m_owner.GetSize();

	m_rect.setSize(size);
	m_rect.setOrigin(size / 2.0f);
	m_rect.setPosition(pos);

	m_rect.setFillColor(m_color);
}

void ez::components::graphics::Renderer::SetTexture(const std::string& path)
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
		m_rect.setFillColor({ 255,255,255,255 });
		m_rect.setTexture(m_texture);
	}
}

void ez::components::graphics::Renderer::SetColor(const sf::Color& color)
{
	m_color = color;
	m_rect.setFillColor(m_color);
}

void ez::components::graphics::Renderer::SetOrder(const int order)
{
	m_order = order;
}

const sf::Texture* ez::components::graphics::Renderer::GetTexture() const
{
	return m_texture;
}

const sf::Color& ez::components::graphics::Renderer::GetColor() const
{
	return m_color;
}

const sf::RectangleShape& ez::components::graphics::Renderer::GetRect() const
{
	return m_rect;
}

const int& ez::components::graphics::Renderer::GetOrder() const
{
	return m_order;
}

void ez::components::graphics::Renderer::Update(float dt, systeme::Systeme& m_systeme)
{
	auto pos = m_owner.GetTransform();
	auto size = m_owner.GetSize();
	m_rect.setPosition(pos);
	m_rect.setSize(size);
}

void ez::components::graphics::Renderer::Render(sf::RenderWindow& m_window)
{
	m_window.draw(m_rect);
}
