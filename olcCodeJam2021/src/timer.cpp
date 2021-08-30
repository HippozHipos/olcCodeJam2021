#include "timer.h"

Timer::Timer() = default;

float Timer::Count() const noexcept
{
	return std::chrono::duration<float>(std::chrono::high_resolution_clock::now() - start).count();
}

void Timer::Reset() noexcept
{
	start = std::chrono::high_resolution_clock::now();
}
