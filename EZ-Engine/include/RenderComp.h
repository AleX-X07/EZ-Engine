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

	void SetTexture(std::string path);
	void SetColor(sf::Color color);

	sf::Texture* GetTexture();
	sf::Color& GetColor();
	sf::RectangleShape& GetRect();

	virtual void Update(float dt, Systeme* m_systeme) override;
	virtual void Render(sf::RenderWindow* m_window) override;
};