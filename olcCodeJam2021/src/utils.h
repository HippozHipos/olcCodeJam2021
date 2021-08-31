#pragma once
#include "olcPixelGameEngine.h"

inline bool pointInRect(const olc::vf2d& mouse, const olc::vf2d& pos, const olc::vf2d& size)
{
	return
		mouse.x > pos.x && mouse.x < pos.x + size.x &&
		mouse.y > pos.y && mouse.y < pos.y + size.y;
}

inline bool rectInRect(const olc::vf2d& r1Pos, const olc::vf2d& r1Size, const olc::vf2d& r2Pos, const olc::vf2d& r2Size)
{
	return
		r1Pos.x < r2Pos.x + r2Pos.x &&
		r1Pos.x + r1Pos.x > r2Pos.x &&
		r1Pos.y < r2Pos.y + r2Pos.y &&
		r1Pos.y + r1Pos.y > r2Pos.y;
}

struct constants
{
	static constexpr float PI = 3.141592653589793238462643383f;
};
