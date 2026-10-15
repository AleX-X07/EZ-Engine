#pragma once

#include <Input.h>
#include <GameScene.h>

struct Systeme
{ 
	Input* m_input;
	GameScene* m_gamescene;

	Systeme();
	~Systeme();
};