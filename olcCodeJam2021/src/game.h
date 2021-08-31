#pragma once
#include "character.h"
#include "characterCreator.h"
#include "levelManager.h"

class Game
{
public:
	Game();

public:
	void Init(olc::Decal* spriteSheet, olc::Decal* bulletSpriteSheet);
	void Run(olc::PixelGameEngine* pge) noexcept;

private:

private:
	Character& player;
	PlayerCreator playerCreator{};
	LevelManager levelManager{};
};