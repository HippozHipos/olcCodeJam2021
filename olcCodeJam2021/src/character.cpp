#include "character.h"
#include "renderer.h"
#include "controller.h"
#include "attacker.h"
#include <assert.h>

Character::Character() = default;

Character::Character(const olc::vf2d& position, ControllerInterface* controller, AttackInterface* attacker) :
	position{ position }, slimeSpriteSheet{ slimeSpriteSheet }, controller{ controller }, attacker{ attacker }
{
}

Character::~Character()
{
	delete controller;
	delete attacker;
}

void Character::Init(olc::Decal* slimeSpriteSheet, olc::Decal* bulletSpriteSheet) noexcept
{
	this->slimeSpriteSheet = slimeSpriteSheet;
	this->bulletSpriteSheet = bulletSpriteSheet;
}

void Character::DoSlimeAnimation(olc::PixelGameEngine* pge, SlimeAnimation::Type slimeType) noexcept
{
	assert(slimeSpriteSheet != nullptr && "Character class not initialised");
	assert(bulletSpriteSheet != nullptr && "Character class not initialised");
	SlimeAnimation::PartialDecalInfo info = slimeAnimation.GetPartialDecalInfo(pge->GetElapsedTime(), 15, slimeType);
	DrawSlimeAnimation(pge, position, slimeSpriteSheet, info);
}

void Character::RunController(olc::PixelGameEngine* pge) noexcept
{
	if (controller != nullptr)
	{
		controller->Control(pge, *this);
	}
}

void Character::RunAttacker(olc::PixelGameEngine* pge) noexcept
{
	attacker->Attack(pge);
	attacker->AddBullet(pge, *this);
	attacker->RenderBullet(pge, bulletSpriteSheet);
}

