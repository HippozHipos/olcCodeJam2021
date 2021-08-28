#include "olcPixelGameEngine.h"
#include "slimeAnimation.h"
#include "ui.h"
#include "renderer.h"
#include "state.h"

class HomePageNonInteractive
{
public:
	HomePageNonInteractive();

public:
	void DoSlimeAnimation(olc::PixelGameEngine* pge, float elapsedTime, olc::Decal* spriteSheet) noexcept;
	void DrawWalls(olc::PixelGameEngine* pge, olc::Decal* sprite) noexcept;
	void DrawAboutString(olc::PixelGameEngine* pge) const noexcept;

private:
	SlimeAnimation animation{};
	float wallRotationAngle = 0.0f;
};

class HomePageInteractive
{
public:
	HomePageInteractive();

public:
	void Init(olc::Decal* spriteSheet) noexcept;
	void DrawButtons(olc::PixelGameEngine* pge) noexcept;
	void ExecuteButtonFunctionOnClick() const noexcept;

private:
	Ui ui{};
};

class HomePage
{
public:
	HomePage();

public:
	void Init(olc::Decal* spriteSheet) noexcept;
	void Run(olc::PixelGameEngine* pge, float elapsedTime, olc::Decal* slimeSpriteSheet, olc::Decal* wallSprite) noexcept;

private:
	HomePageInteractive interactive{};
	HomePageNonInteractive nonInteractive{};
};