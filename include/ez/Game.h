#pragma once
#include <SFML/Graphics.hpp>

#include <ez/GameScene.h>

namespace ez
{
	class Game
	{
	private:
		std::vector<GameScene*> myScenes;
		GameScene* current_scene;

		sf::RenderWindow& m_window;

	public:
		Game(sf::RenderWindow& window);
		virtual ~Game();

		GameScene* AddScene(const std::string& name);
		void SetCurrentScene(const std::string& name);

		void SetWindow(sf::RenderWindow* window);

		virtual void Init();

		virtual void Update(float dt, systeme::Systeme& m_systeme);
		virtual void Render(sf::RenderWindow& m_window);

		GameScene* GetScene(const std::string& name);
		sf::RenderWindow& GetWindow();
	};
}