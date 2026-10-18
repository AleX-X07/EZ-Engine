#include "ExempleGame.h"

ExempleGame::ExempleGame() : Game()
{
}

ExempleGame::~ExempleGame()
{
}

void ExempleGame::Init()
{
	// First Scene TestZone
	AddScene("Test");
	auto* m_scene = GetScene("Test");
	{
		m_scene->AddObject("Obj");
		auto* obj1 = m_scene->GetObject("Obj");
	}
}
