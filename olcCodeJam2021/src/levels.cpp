#include "levels.h"

LevelInterface::LevelInterface()
{
}

const LevelInterface::LevelData& LevelInterface::GetLevelData() const noexcept
{
	return levelData;
}

Level1::Level1()
{
	MakeLevelData();
}

void Level1::MakeLevelData() noexcept
{
	levelData.enemies.push_back(enemyCreator.CreateBackAndForthAndGet({ 50.0f, 50.0f }, { 50.0f, 50.0f }, { 500.0f, 50.0f }).get());
}
