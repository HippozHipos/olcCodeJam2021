#include "game.h"
#include "controller.h"

Game::Game() :
	player{ *playerCreator.CreateAndGet({250.0f, 550.0f}).get() }
{
}

void Game::Run(olc::PixelGameEngine* pge) noexcept
{
	levelManager.Run(pge);
	player.DoSlimeAnimation(pge, SlimeAnimation::Type::NOEYES);
	player.RunController(pge);
	player.RunAttacker(pge);
}

void Game::Init(olc::Decal* slimeSpriteSheet, olc::Decal* bulletSpriteSheet)
{
	player.Init(slimeSpriteSheet, bulletSpriteSheet);
	levelManager.Init(slimeSpriteSheet);
}
