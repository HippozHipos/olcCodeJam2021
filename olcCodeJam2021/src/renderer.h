#pragma once
#include "olcPixelGameEngine.h"
#include "button.h"
#include "utils.h"

void DrawButton(olc::PixelGameEngine* pge, Button& button) noexcept
{
	pge->DrawDecal(button.position, button.GetDecal());
}
