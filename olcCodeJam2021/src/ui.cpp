#include "ui.h"
#include "state.h"

void Ui::InitButtons(olc::Decal* buttonSpriteSheet) noexcept
{
	startGameButton = Button({ 180.0f, 200.0f }, "Start Game", buttonSpriteSheet, State::States::INTRO);
	aboutButton = Button({ 180.0f, 280.0f }, "About", buttonSpriteSheet, State::States::ABOUTPAGE);
}
