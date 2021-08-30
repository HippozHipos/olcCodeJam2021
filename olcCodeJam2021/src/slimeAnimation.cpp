#include "slimeAnimation.h"

SlimeAnimation::SlimeAnimation() = default;

SlimeAnimation::PartialDecalInfo::PartialDecalInfo(Type type, int x) :
	x{ x }
{
	switch (type)
	{
	case Type::EYES: y = 143; break;
	case Type::NOEYES: y = 200; break;
	case Type::EYESLEFT: y = 17; break;
	case Type::EYESRIGHT: y = 81; break;
	case Type::RED: y = 250; break;
	}
}

SlimeAnimation::PartialDecalInfo SlimeAnimation::GetPartialDecalInfo(float elapsedTime, float speed, Type type) noexcept
{
	totalElapsedTime += elapsedTime;
	if (totalElapsedTime > INFINITY - 10.0f) totalElapsedTime = 0;
	int index = (int)((std::sin(totalElapsedTime * speed) + 1.0f) * 0.5f * 8.0f);
	return PartialDecalInfo(type, index);
}
