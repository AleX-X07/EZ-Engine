#pragma once
#include <Game.h>

class ExempleGame :
	public Game
{
public:
	ExempleGame();
	virtual ~ExempleGame() override;

	virtual void Init() override;
};