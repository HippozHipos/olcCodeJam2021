#pragma once
#include "olcPixelGameEngine.h"
#include "button.h"
#include "utils.h"
#include "slimeAnimation.h"

void DrawButtonSprite(olc::PixelGameEngine* pge, Button& button) noexcept;
void DrawButtonText(olc::PixelGameEngine* pge, Button& button) noexcept; 
void DrawButton(olc::PixelGameEngine* pge, Button& button) noexcept;
void DrawSlimeAnimation(olc::PixelGameEngine* pge, const olc::vf2d& pos, olc::Decal* spriteSheet, 
	SlimeAnimation::PartialDecalInfo info, const olc::vf2d& scale = { 1.0f, 1.0f });
void DrawWall(olc::PixelGameEngine* pge, const olc::vf2d& pos, olc::Decal* sprite,
	float angle, const olc::vf2d& centre = { 45.0f, 11.5f }, const olc::vf2d & scale = { 1.8f, 1.8f });
void DrawDialougeBox(float x, olc::PixelGameEngine* pge, olc::Decal* spriteSheet, bool glooSpeaking);
void DrawDialougeBoxText(olc::PixelGameEngine* pge, const std::string& text);
void DrawBullet(const olc::vf2d& position, olc::PixelGameEngine* pge, olc::Decal* spriteSheet, bool playerAttacking);

