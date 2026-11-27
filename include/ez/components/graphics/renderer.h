#pragma once
#include <SFML/Graphics.hpp>

#include <ez/Component.h>

namespace ez::components::graphics
{
	class Renderer final :
		public ez::Component
	{
	private:
		sf::RectangleShape m_rect;
		sf::Color m_color;

		sf::Texture* m_texture;

	public:
		Renderer(ez::GameObject* owner);
		virtual ~Renderer() = default;

		void SetTexture(const std::string& path);
		void SetColor(const sf::Color& color);

		const sf::Texture* GetTexture() const;
		const sf::Color& GetColor() const;
		const sf::RectangleShape& GetRect() const;

		virtual void Update(float dt, systeme::Systeme& m_systeme) override;
		virtual void Render(sf::RenderWindow& m_window) override;
	};
}