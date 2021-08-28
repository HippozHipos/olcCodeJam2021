#pragma once
#include "olcPixelGameEngine.h"
#include "button.h"

class Ui
{
public:
	Ui() = default;

public:
	void InitButtons(olc::Decal* buttonSpriteSheet) noexcept;

public:
	Button startGameButton;
	Button aboutButton;
};