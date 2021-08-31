#include "renderer.h"

void DrawButtonSprite(olc::PixelGameEngine* pge, Button& button) noexcept
{
	olc::vf2d position{ button.xStart, 0.0f };
	if (!button.MouseOverButton(pge)) position.y = button.yStarts[0];
	else position.y = button.yStarts[1];
	if (button.Held(pge)) position.y = button.yStarts[2];
	pge->DrawPartialDecal(button.position, button.GetDecal(), position, button.size);
}

void DrawButtonText(olc::PixelGameEngine* pge, Button& button) noexcept
{
	olc::Pixel color;
	if (!button.MouseOverButton(pge)) color = { 194, 168, 144 };
	else color = { 88, 88, 88 };
	if (button.Held(pge)) color = { 185, 122, 86 };
	pge->DrawStringDecal(button.position + olc::vf2d{ 10.0f, 25.0f }, button.GetText(), color, { 2.8f, 3.2f });
}

void DrawButton(olc::PixelGameEngine* pge, Button& button) noexcept
{
	DrawButtonSprite(pge, button);
	DrawButtonText(pge, button);
}

void DrawSlimeAnimation(olc::PixelGameEngine* pge, const olc::vf2d& pos, olc::Decal* spriteSheet, SlimeAnimation::PartialDecalInfo info, const olc::vf2d& scale)
{
	pge->DrawPartialDecal(pos, spriteSheet, { (float)info.x * info.size.x, (float)info.y }, (olc::vf2d)info.size, scale);
}

void DrawWall(olc::PixelGameEngine* pge, const olc::vf2d& pos, olc::Decal* sprite, float angle, const olc::vf2d& centre, const olc::vf2d& scale)
{
	pge->DrawRotatedDecal(pos, sprite, angle, centre, scale);
}

void DrawDialougeBox(float x, olc::PixelGameEngine* pge, olc::Decal* spriteSheet, bool glooSpeaking)
{
	float y = glooSpeaking ? 200.0f: 0.0f;
	pge->DrawPartialDecal({ x, 400.0f }, spriteSheet, { 0.0f, y }, { 600.0f, 200.0f });
}

void DrawDialougeBoxText(olc::PixelGameEngine* pge, const std::string& text)
{
	pge->DrawStringDecal({ 40.0f , 430.0f }, text, { 88, 88, 88 }, { 1.5f, 2.5f });
}

void DrawBullet(const olc::vf2d& position, olc::PixelGameEngine* pge, olc::Decal* spriteSheet, bool playerAttacking)
{
	olc::vf2d sourcePos = playerAttacking ? olc::vf2d{ 0.0f, 0.0f } : olc::vf2d{ 8.0f, 0.0f };
	pge->DrawPartialDecal(position, spriteSheet, sourcePos, { 8.0f, 15.0f });
}



