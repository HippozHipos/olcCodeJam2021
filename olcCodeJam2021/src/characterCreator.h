#pragma once
#include "character.h"
#include "controller.h"
#include "olcPixelGameEngine.h"

class PlayerCreator
{
public:
	PlayerCreator();
	std::unique_ptr<Character>& CreateAndGet(const olc::vf2d& position) noexcept;

private:
	std::unique_ptr<Character> player;
};

class EnemyCreator
{
public:
	EnemyCreator();
	std::unique_ptr<Character>& CreateBackAndForthAndGet(const olc::vf2d& position, const olc::vf2d& from, const olc::vf2d& to) noexcept;

private:
	std::vector<std::unique_ptr<Character>> enemies;
};