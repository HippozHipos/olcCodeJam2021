#include "slimeAnimation.h"

SlimeAnimation::SlimeAnimation() = default;


SlimeAnimation::PartialDecalInfo::PartialDecalInfo(bool eye, int x) :
	x{ x }
{
	y = eye ? 143 : 200;
}

SlimeAnimation::PartialDecalInfo SlimeAnimation::GetPartialDecalInfo(float elapsedTime, float speed, bool eye) noexcept
{
	totalElapsedTime += elapsedTime;
	if (totalElapsedTime > INFINITY - 10.0f) totalElapsedTime = 0;
	int index = (int)((std::sin(totalElapsedTime * speed) + 1.0f) * 0.5f * 8.0f);
	return PartialDecalInfo(eye, index);
}
