#pragma once
#include "olcPixelGameEngine.h"
#include "slimeAnimation.h"

class ControllerInterface;
//Class for player and enemies
class Character
{
public:
	Character();
	Character(const olc::vf2d& position, ControllerInterface* controller);
	~Character();

public:
	void Init(olc::Decal* spriteSheet) noexcept;
	void DoSlimeAnimation(olc::PixelGameEngine* pge, SlimeAnimation::Type slimeType) noexcept;
	void RunController(olc::PixelGameEngine* pge) noexcept;

public:
	olc::vf2d position{};

private:
	SlimeAnimation slimeAnimation{};
	olc::Decal* spriteSheet{};
	ControllerInterface* controller{};
};
