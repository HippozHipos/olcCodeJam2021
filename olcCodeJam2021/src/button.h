#pragma once
#include "olcPixelGameEngine.h"
#include "state.h"

class Button
{
public:
	Button();
	Button(const olc::vf2d& position, const std::string& text, olc::Decal* sprite, State::States state);

public:
	olc::vf2d position{};

	//start of all the buttons in the sprite
	float xStart = 7.0f;
	//start of all the buttons in the sprite
	olc::vf2d size = { 244.0f, 72.0f };
    //                      normal, mouse over button, button clicked
	std::vector<float> yStarts = { 9.0f, 100.0f, 193.0f };
	olc::Decal* GetDecal() const noexcept;
	bool MouseOverButton(const olc::PixelGameEngine* const pge) const noexcept;
	bool Clicked(const olc::PixelGameEngine* const pge) const noexcept;
	bool Held(const olc::PixelGameEngine* const pge) const noexcept;
	const std::string& GetText() const noexcept;
	void ChangeStateOnClick(const olc::PixelGameEngine* const pge) const noexcept;

private:
	olc::Decal* decal{};
	State::States state{};
	std::string text{};
};
