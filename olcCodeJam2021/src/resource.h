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
	olc::Sprite* GetDialougeBoxSprite() noexcept;
	olc::Decal* GetDialougeBoxDecal() noexcept;
	olc::Sprite* GetMenuBackgroundSprite() noexcept;
	olc::Decal* GetMenuBackgroundDecal() noexcept;
	olc::Sprite* GetGameBackgroundSprite() noexcept;
	olc::Decal* GetGameBackgroundDecal() noexcept;
	olc::Sprite* GetBulletSprite() noexcept;
	olc::Decal* GetBulletDecal() noexcept;

private:
	std::unique_ptr<olc::Sprite> buttonSprite = nullptr;
	std::unique_ptr<olc::Sprite> slimeSprite = nullptr;
	std::unique_ptr<olc::Sprite> wallSprite = nullptr;
	std::unique_ptr<olc::Sprite> dialougeBoxSprite = nullptr;
	std::unique_ptr<olc::Sprite> backgroundSprite = nullptr;
	std::unique_ptr<olc::Sprite> gBackgroundSprite = nullptr; 
	std::unique_ptr<olc::Sprite> bulletSprite = nullptr;

	std::unique_ptr<olc::Decal> buttonDecal = nullptr;
	std::unique_ptr<olc::Decal> slimeDecal = nullptr;
	std::unique_ptr<olc::Decal> wallDecal = nullptr;
	std::unique_ptr<olc::Decal> dialougeBoxDecal = nullptr;
	std::unique_ptr<olc::Decal> backgroundDecal = nullptr;
	std::unique_ptr<olc::Decal> gBackgroundDecal = nullptr;
	std::unique_ptr<olc::Decal> bulletDecal = nullptr;
};