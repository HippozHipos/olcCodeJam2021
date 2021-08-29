#include "homePage.h"

HomePageNonInteractive::HomePageNonInteractive() = default;

void HomePageNonInteractive::DoSlimeAnimation(olc::PixelGameEngine* pge, float elapsedTime, olc::Decal* spriteSheet) noexcept
{
	SlimeAnimation::PartialDecalInfo info = animation.GetPartialDecalInfo(elapsedTime, 15.0f, true);
	DrawSlimeAnimation(pge, { 230.0f, 90.0f }, spriteSheet, info, { 2.0f, 2.0f });
}

void HomePageNonInteractive::DrawWalls(olc::PixelGameEngine* pge, olc::Decal* sprite) noexcept
{
	wallRotationAngle += pge->GetElapsedTime() * 2.0f;
	DrawWall(pge, { 100.0f, 100.0f }, sprite, wallRotationAngle);
	DrawWall(pge, { 500.0f, 100.0f }, sprite, wallRotationAngle * -1.0f);
}

void HomePageNonInteractive::DrawAboutString(olc::PixelGameEngine* pge) const noexcept
{
	pge->DrawStringDecal({ 50.0f, 430.0f }, "OlcCodeJam 2021 Entry\n\n    - Time Lag -", { 201, 167, 133 }, { 3.0f, 3.0f });
}

HomePageInteractive::HomePageInteractive() = default;

void HomePageInteractive::Init(olc::Decal * spriteSheet) noexcept
{
	ui.InitButtons(spriteSheet);
}

void HomePageInteractive::DrawButtons(olc::PixelGameEngine* pge) noexcept
{
	DrawButton(pge, ui.startGameButton);
	DrawButton(pge, ui.aboutButton);
}

void HomePageInteractive::ExecuteButtonFunctionOnClick(olc::PixelGameEngine* pge) noexcept
{
	ui.aboutButton.ChangeStateOnClick(pge);
	ui.startGameButton.ChangeStateOnClick(pge);
}

HomePage::HomePage() = default;

void HomePage::Init(olc::Decal* spriteSheet) noexcept
{
	interactive.Init(spriteSheet);
}

void HomePage::Run(olc::PixelGameEngine* pge, float elapsedTime, olc::Decal* slimeSpriteSheet, olc::Decal* wallSprite) noexcept
{
	interactive.DrawButtons(pge);
	interactive.ExecuteButtonFunctionOnClick(pge);
	nonInteractive.DoSlimeAnimation(pge, elapsedTime, slimeSpriteSheet);
	nonInteractive.DrawWalls(pge, wallSprite);
	nonInteractive.DrawAboutString(pge);
}
