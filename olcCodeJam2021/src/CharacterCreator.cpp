#include "characterCreator.h"
#include "controller.h"
#include "attacker.h"

PlayerCreator::PlayerCreator() = default;

std::unique_ptr<Character>& PlayerCreator::CreateAndGet(const olc::vf2d & position) noexcept
{
	player = std::make_unique<Character>(position, new PlayerController{}, new PlayerAttacker{});
	return player;
}

EnemyCreator::EnemyCreator() = default;

std::unique_ptr<Character>& EnemyCreator::CreateBackAndForthAndGet(const olc::vf2d& position, const olc::vf2d & from, const olc::vf2d & to) noexcept
{
	enemies.push_back(std::make_unique<Character>(position, new BackAndForthController{from, to}, nullptr));
	return enemies.back();
}
