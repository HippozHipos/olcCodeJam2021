#pragma once
#include "olcPixelGameEngine.h"
#include <string>
#include "timer.h"
#include "slimeAnimation.h"
#include "olcPixelGameEngine.h"
#include "state.h"
#include "script.h"

class DialougeBoxExtender
{
public:
	DialougeBoxExtender();
	
public:
	float GetExtendedX(olc::PixelGameEngine* pge) noexcept;
	bool FinishedExtention() const noexcept;

private:
	float x = -600.0f;
	float speed = 800.0f;
};

class DialougeManager
{
public:
	DialougeManager();

public:
	void IncrementDialougeOnSpacePress(olc::PixelGameEngine* pge, size_t scriptSize) noexcept;
	size_t GetCurrentDialouge() const noexcept;

private:
	size_t currentDialouge = 0;
};

class BlinkingColor
{
public:
	BlinkingColor();

	olc::Pixel GetColor(olc::PixelGameEngine* pge, float speed) noexcept;

private:
	float totalElapsedTime = 0.0f;
};

class Dialouge
{
public:
	Dialouge();

public:
	void Run(olc::PixelGameEngine* pge, olc::Decal* slimeSpriteSheet, olc::Decal* dialougeSpriteSheet) noexcept;

private:
	bool GloosTurn() const noexcept;
	void Say(olc::PixelGameEngine* pge, olc::Decal* spriteSheet) noexcept;
	void DoSlimeAnimation(olc::PixelGameEngine* pge, olc::Decal* spriteSheet) noexcept;
	void DrawPressSpaceText(olc::PixelGameEngine* pge);
	
private:
	int speechCount = 0;
	DialougeManager manager{};
	DialougeBoxExtender boxAnimator{};
	SlimeAnimation slimeAnimation{};
	BlinkingColor blinkingColor{};
	Script script{};
};
