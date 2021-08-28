#pragma once
#include "olcPixelGameEngine.h"
#include "state.h"

class Button
{
public:
	Button() = default;
	Button(const olc::vf2d& position, olc::Sprite* sprite, std::function<void(State::States)> function);

public:
	olc::vf2d position{};
	olc::Decal* GetDecal() const noexcept;

private:
	std::unique_ptr<olc::Sprite> sprite{};
	std::unique_ptr<olc::Decal> decal{};
	std::function<void(State::States)> function{};
};
