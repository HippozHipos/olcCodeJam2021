#include "resource.h"

void SpriteSheets::Load() noexcept
{
	buttonSprite = std::make_unique<olc::Sprite>("resources\\button sprite sheet.png");
	slimeSprite = std::make_unique<olc::Sprite>("resources\\slime sprite sheet.png");
	wallSprite = std::make_unique<olc::Sprite>("resources\\wall sprite.png");
}

void SpriteSheets::MakeDecalsFromSprites() noexcept
{
	buttonDecal = std::make_unique<olc::Decal>(buttonSprite.get());
	slimeDecal = std::make_unique<olc::Decal>(slimeSprite.get());
	wallDecal = std::make_unique<olc::Decal>(wallSprite.get());
}

olc::Sprite* SpriteSheets::GetButtonSprite() noexcept
{
	return buttonSprite.get();
}

olc::Decal* SpriteSheets::GetButtonDecal() noexcept
{
	return buttonDecal.get();
}

olc::Sprite* SpriteSheets::GetSlimeSprite() noexcept
{
	return slimeSprite.get();
}

olc::Decal* SpriteSheets::GetSlimeDecal() noexcept
{
	return slimeDecal.get();
}

olc::Sprite* SpriteSheets::GetWallSprite() noexcept
{
	return wallSprite.get();
}

olc::Decal* SpriteSheets::GetWallDecal() noexcept
{
	return wallDecal.get();
}


