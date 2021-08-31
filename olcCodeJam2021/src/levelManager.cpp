#include "levelManager.h"

LevelCreator::LevelCreator()
{
	level1 = std::make_unique<Level1>();
}

LevelRunner::LevelRunner() = default;

void LevelRunner::Init(olc::Decal * spriteSheet, const LevelInterface* level) noexcept
{
	for (auto& enemy : level->GetLevelData().enemies)
	{
		enemy->Init(spriteSheet, nullptr);
	}
}

void LevelRunner::Run(olc::PixelGameEngine* pge, const LevelInterface * level) noexcept
{
	for (auto& enemy : level->GetLevelData().enemies)
	{
		enemy->DoSlimeAnimation(pge, SlimeAnimation::Type::RED);
		enemy->RunController(pge);
	}
}

LevelManager::LevelManager()
{
	levels.push_back(levelCreator.level1.get());
}

void LevelManager::Init(olc::Decal* slimeSpriteSheet) noexcept
{
	levelRunner.Init(slimeSpriteSheet, levels[currentLevel - 1]);
}

void LevelManager::Run(olc::PixelGameEngine* pge) noexcept
{
	levelRunner.Run(pge, levels[currentLevel - 1]);
}

