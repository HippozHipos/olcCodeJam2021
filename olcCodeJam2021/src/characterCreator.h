#pragma once
#include "character.h"
#include "controller.h"
#include "olcPixelGameEngine.h"

class PlayerCreator
{
public:
	PlayerCreator();
	std::unique_ptr<Character>& CreateAndGet(olc::vf2d position) noexcept;

private:
	std::unique_ptr<Character> player;
};

class EnemyCreator
{

};