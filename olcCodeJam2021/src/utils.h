
#pragma once
#include "olcPixelGameEngine.h"

bool mouseInRect(const olc::vf2d& mouse, const olc::vf2d& pos, const olc::vf2d& size)
{
	if (
		(mouse.x > pos.x && mouse.x < pos.x + size.x) &&
		(mouse.y > pos.y && mouse.y < pos.y + size.y)
		)
		return true;
	return false;
}
