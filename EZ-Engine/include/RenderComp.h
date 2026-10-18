#pragma once
#include <SFML/Graphics.hpp>

#include <Component.h>

class RenderComp final :
	public Component  
{
private:
	sf::RectangleShape m_rect;
	sf::Color m_color;

	sf::Texture* m_texture;

public:
	RenderComp(GameObject* owner);
	virtual ~RenderComp() = default;

	virtual void Update(float dt, Systeme* m_systeme) override;
	virtual void Render(sf::RenderWindow* m_window) override;
};