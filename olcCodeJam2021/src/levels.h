#pragma once
#include "olcPixelGameEngine.h"
#include "characterCreator.h"

class LevelInterface
{
public:
	struct LevelData
	{
		std::vector<Character*> enemies;
	};

	LevelInterface();

	const LevelData& GetLevelData() const noexcept;


protected:
	virtual void MakeLevelData() noexcept = 0;
	EnemyCreator enemyCreator{};
	LevelData levelData;
};

class Level1 : public LevelInterface
{
public:
	Level1();

private:
	void MakeLevelData() noexcept override;
};