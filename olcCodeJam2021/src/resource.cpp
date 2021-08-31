#include "resource.h"

void SpriteSheets::Load() noexcept
{
	buttonSprite = std::make_unique<olc::Sprite>("resources\\button sprite sheet.png");
	slimeSprite = std::make_unique<olc::Sprite>("resources\\slime sprite sheet.png");
	wallSprite = std::make_unique<olc::Sprite>("resources\\wall sprite.png");
	dialougeBoxSprite = std::make_unique<olc::Sprite>("resources\\dialouge box sprite sheet.png");
	backgroundSprite = std::make_unique<olc::Sprite>("resources\\background sprite.png");
	gBackgroundSprite = std::make_unique<olc::Sprite>("resources\\gbackground sprite.png");
	bulletSprite = std::make_unique<olc::Sprite>("resources\\bullet sprite sheet.png");
}

void SpriteSheets::MakeDecalsFromSprites() noexcept
{
	buttonDecal = std::make_unique<olc::Decal>(buttonSprite.get());
	slimeDecal = std::make_unique<olc::Decal>(slimeSprite.get());
	wallDecal = std::make_unique<olc::Decal>(wallSprite.get());
	dialougeBoxDecal = std::make_unique<olc::Decal>(dialougeBoxSprite.get());
	backgroundDecal = std::make_unique<olc::Decal>(backgroundSprite.get());
	gBackgroundDecal = std::make_unique<olc::Decal>(gBackgroundSprite.get());
	bulletDecal = std::make_unique<olc::Decal>(bulletSprite.get());
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

olc::Sprite* SpriteSheets::GetDialougeBoxSprite() noexcept
{
	return dialougeBoxSprite.get();
}

olc::Decal* SpriteSheets::GetDialougeBoxDecal() noexcept
{
	return dialougeBoxDecal.get();
}

olc::Sprite* SpriteSheets::GetMenuBackgroundSprite() noexcept
{
	return backgroundSprite.get();
}

olc::Decal* SpriteSheets::GetMenuBackgroundDecal() noexcept
{
	return backgroundDecal.get();
}

olc::Sprite* SpriteSheets::GetGameBackgroundSprite() noexcept
{
	return gBackgroundSprite.get();
}

olc::Decal* SpriteSheets::GetGameBackgroundDecal() noexcept
{
	return gBackgroundDecal.get();
}

olc::Sprite* SpriteSheets::GetBulletSprite() noexcept
{
	return bulletSprite.get();
}

olc::Decal* SpriteSheets::GetBulletDecal() noexcept
{
	return bulletDecal.get();
}

