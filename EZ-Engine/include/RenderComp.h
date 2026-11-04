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

	int m_order = 0;

public:
	RenderComp(GameObject* owner);
	virtual ~RenderComp() = default;

	void SetTexture(std::string path);
	void SetColor(sf::Color color);
	void SetOrder(int n_order);

	const sf::Texture* GetTexture() const;
	const sf::Color& GetColor() const;
	const sf::RectangleShape& GetRect() const;
	const int& GetOrder() const;

	virtual void Update(float dt, Systeme* m_systeme) override;
	virtual void Render(sf::RenderWindow* m_window) override;
};