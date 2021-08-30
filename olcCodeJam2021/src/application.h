#pragma once
#include "olcPixelGameEngine.h"
#include "homePage.h"
#include "resource.h"
#include "dialogue.h"
#include "state.h"
#include "game.h"

class Application : public olc::PixelGameEngine
{
public:
	Application();

public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float elapsedTime) override;

private:
	HomePage homePage{};
	SpriteSheets spriteSheets{};
	Dialouge dialouge{};
	Script script{};
	Game game{};
};
