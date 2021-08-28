#include "button.h"

Button::Button(const olc::vf2d& position, olc::Sprite* sprite, std::function<void(State::States)> function) :
	position{ position },
	sprite{ sprite },
	function{ function }
{
	decal = std::make_unique<olc::Decal>(sprite);
}

olc::Decal* Button::GetDecal() const noexcept
{
	return decal.get();
}
