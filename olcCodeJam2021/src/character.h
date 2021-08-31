#pragma once
#include "olcPixelGameEngine.h"
#include "slimeAnimation.h"

class ControllerInterface;
class AttackInterface;
//Class for player and enemies
class Character
{
public:
	Character();
	Character(const olc::vf2d& position, ControllerInterface* controller, AttackInterface* attacker);
	~Character();

public:
	void Init(olc::Decal* slimeSpriteSheet, olc::Decal* bulletSpriteSheet) noexcept;
	void DoSlimeAnimation(olc::PixelGameEngine* pge, SlimeAnimation::Type slimeType) noexcept;
	void RunController(olc::PixelGameEngine* pge) noexcept;
	void RunAttacker(olc::PixelGameEngine* pge) noexcept;

public:
	olc::vf2d position{};

private:
	SlimeAnimation slimeAnimation{};
	olc::Decal* slimeSpriteSheet{};
	olc::Decal* bulletSpriteSheet{};
	ControllerInterface* controller{};
	AttackInterface* attacker{};
	int hp{};
};
