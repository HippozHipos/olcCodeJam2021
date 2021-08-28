#include "renderer.h"

void DrawButton(olc::PixelGameEngine* pge, Button& button) noexcept
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
