#include "character.h"
#include "renderer.h"
#include "controller.h"
#include <assert.h>

Character::Character() = default;

Character::Character(const olc::vf2d& position, ControllerInterface* controller) :
	position{ position }, spriteSheet{ spriteSheet }, controller{ controller }
{
}

Character::~Character()
{
	delete controller;
}

void Character::Init(olc::Decal* spriteSheet) noexcept
{
	this->spriteSheet = spriteSheet;
}

void Character::DoSlimeAnimation(olc::PixelGameEngine* pge) noexcept
{
	assert(spriteSheet != nullptr && "Character class not initialised");
	SlimeAnimation::PartialDecalInfo info = slimeAnimation.GetPartialDecalInfo(pge->GetElapsedTime(), 15, SlimeAnimation::Type::NOEYES);
	DrawSlimeAnimation(pge, position, spriteSheet, info);
}

void Character::RunController(olc::PixelGameEngine* pge) noexcept
{
	if (controller != nullptr)
	{
		controller->Control(pge, *this);
	}
}

