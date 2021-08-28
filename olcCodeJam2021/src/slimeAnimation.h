#pragma once
#include "olcPixelGameEngine.h"

class SlimeAnimation
{
public:
	SlimeAnimation();

	struct PartialDecalInfo
	{
		PartialDecalInfo(bool eye, int x);
		olc::vi2d size{ 64, 49 };
		int x{};
		int y{};
	};

public:
	PartialDecalInfo GetPartialDecalInfo(float elapsedTime, float speed, bool eye = false) noexcept;

private:
	float totalElapsedTime = 0.0f;
};
