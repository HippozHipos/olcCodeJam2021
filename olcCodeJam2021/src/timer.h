#pragma once
#include <chrono>

class Timer
{
public:
	Timer();

	float Count() const noexcept;
	void Reset() noexcept;

private:
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
};