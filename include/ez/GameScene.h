#pragma once
#include <SFML/Graphics.hpp>

#include <map>

#include <ez/GameObject.h>

namespace ez
{
	class GameScene
	{
	private:
		const std::string m_name;

		std::vector<GameObject*> m_objects;

		bool sort = false;
		std::map<int, std::vector<GameObject*>> m_render;

	public:
		GameScene(const std::string& name);
		~GameScene();

		GameObject* AddObject(const std::string& name);

		void Update(float dt, systeme::Systeme& m_systeme);
		void Render(sf::RenderWindow& m_window);

		GameObject* GetObject(const std::string& name);
		const std::string& GetName() const;
		std::vector<GameObject*>& GetListObject();
	};

}