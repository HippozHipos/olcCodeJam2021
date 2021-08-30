#pragma once
#include "olcPixelGameEngine.h"

class SlimeAnimation
{
public:
	SlimeAnimation();
	enum class Type
	{
		NOEYES, EYES, EYESLEFT, EYESRIGHT, RED
	};

	struct PartialDecalInfo
	{
		PartialDecalInfo(Type type, int x);
		olc::vi2d size{ 64, 49 };
		int x{};
		int y{};
	};

public:
	PartialDecalInfo GetPartialDecalInfo(float elapsedTime, float speed, Type type) noexcept;

private:
	float totalElapsedTime = 0.0f;
};
