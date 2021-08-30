#include "characterCreator.h"

PlayerCreator::PlayerCreator() = default;

std::unique_ptr<Character>& PlayerCreator::CreateAndGet(olc::vf2d position) noexcept
{
	player = std::make_unique<Character>(position, new PlayerController{});
	return player;
}
