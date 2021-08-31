#include "button.h"
#include "utils.h"

Button::Button() = default;

Button::Button(const olc::vf2d& position, const std::string& text, olc::Decal* decal, State::States state) :
	position{ position },
	decal{ decal },
	state{ state },
	text{ text }
{
}

olc::Decal* Button::GetDecal() const noexcept
{
	return decal;
}

bool Button::MouseOverButton(const olc::PixelGameEngine* const pge) const noexcept
{
	if (pointInRect((olc::vf2d)pge->GetMousePos(), position, size))
	{
		return true;
	}
	return false;
}

bool Button::Clicked(const olc::PixelGameEngine* const pge) const noexcept
{
	if (MouseOverButton(pge))
	{
		if (pge->GetMouse(0).bPressed) return true;
	}
	return false;
}

bool Button::Held(const olc::PixelGameEngine* const pge) const noexcept
{
	if (MouseOverButton(pge))
	{
		if (pge->GetMouse(0).bHeld) return true;
	}
	return false;
}

const std::string& Button::GetText() const noexcept
{
	return text;
}

void Button::ChangeStateOnClick(const olc::PixelGameEngine* const pge) noexcept
{	
	change |= Clicked(pge);
	if (change && MouseOverButton(pge) && pge->GetMouse(0).bReleased)
	{
		change = false;
		State::SetCurrentState(state);
	}
}
