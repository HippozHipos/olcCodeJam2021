#pragma once
#include "olcPixelGameEngine.h"

class SpriteSheets
{
public:
	SpriteSheets() = default;

public:
	void Load() noexcept;
	void MakeDecalsFromSprites() noexcept;
	olc::Sprite* GetButtonSprite() noexcept;
	olc::Decal* GetButtonDecal() noexcept;
	olc::Sprite* GetSlimeSprite() noexcept;
	olc::Decal* GetSlimeDecal() noexcept;
	olc::Sprite* GetWallSprite() noexcept;
	olc::Decal* GetWallDecal() noexcept;

private:
	std::unique_ptr<olc::Sprite> buttonSprite = nullptr;
	std::unique_ptr<olc::Sprite> slimeSprite = nullptr;
	std::unique_ptr<olc::Sprite> wallSprite = nullptr;

	std::unique_ptr<olc::Decal> buttonDecal = nullptr;
	std::unique_ptr<olc::Decal> slimeDecal = nullptr;
	std::unique_ptr<olc::Decal> wallDecal = nullptr;
};