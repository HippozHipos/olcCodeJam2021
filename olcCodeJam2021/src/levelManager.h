#pragma once
#include "levels.h"

class LevelCreator
{
public:
	LevelCreator();
	std::unique_ptr<LevelInterface> level1{};
};

class LevelRunner
{
public:
	LevelRunner();
	void Init(olc::Decal* spriteSheet, const LevelInterface* level) noexcept;
	void Run(olc::PixelGameEngine* pge, const LevelInterface* level) noexcept;
};

class LevelManager
{
public:
	LevelManager();

	void Init(olc::Decal* slimeSpriteSheet) noexcept;
	void Run(olc::PixelGameEngine* pge) noexcept;

private:
	size_t currentLevel = 1;
	LevelCreator levelCreator{};
	LevelRunner levelRunner{};
	std::vector<LevelInterface*> levels;
};