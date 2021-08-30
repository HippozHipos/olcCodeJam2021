#include "game.h"
#include "controller.h"

Game::Game() :
	player{ *playerCreator.CreateAndGet({250.0f, 550.0f}).get() }
{
}

void Game::Run(olc::PixelGameEngine* pge) noexcept
{
	player.DoSlimeAnimation(pge, SlimeAnimation::Type::NOEYES);
	player.RunController(pge);
	levelManager.Run(pge);
}

void Game::Init(olc::Decal* spriteSheet)
{
	player.Init(spriteSheet);
	levelManager.Init(spriteSheet);
}
