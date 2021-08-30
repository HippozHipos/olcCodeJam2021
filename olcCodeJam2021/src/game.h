#pragma once
#include "character.h"
#include "characterCreator.h"

class Game
{
public:
	Game();

public:
	void Init(olc::Decal* spriteSheet);
	void Run(olc::PixelGameEngine* pge) noexcept;

private:

private:
	Character& player;
	PlayerCreator playerCreator{};
};