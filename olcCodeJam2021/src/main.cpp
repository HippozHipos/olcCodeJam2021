#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "homePage.h"
#include "resource.h"
#include "dialogue.h"
#include "state.h"

class Application : public olc::PixelGameEngine
{
public:
	Application() { sAppName = "OlcCodeJam 2021 Entry - Time lag"; }

public:
	bool OnUserCreate() override
	{
		spriteSheets.Load();
		spriteSheets.MakeDecalsFromSprites();
		homePage.Init(spriteSheets.GetButtonDecal());
		
		return true;
	}

	bool OnUserUpdate(float elapsedTime) override
	{
		//Clear({ 255,228,196 });

		switch (State::GetCurrentState())
		{
		case State::States::MENU:
		{
			DrawDecal({ 0.0f, 0.0f }, spriteSheets.GetMenuBackgroundDecal());
			SetPixelMode(olc::Pixel::MASK);
			homePage.Run(this, elapsedTime, spriteSheets.GetSlimeDecal(), spriteSheets.GetWallDecal());
			break;
		}
		case State::States::INTRO:
		{
			DrawDecal({ 0.0f, 0.0f }, spriteSheets.GetGameBackgroundDecal());
			SetPixelMode(olc::Pixel::MASK);
			dialouge.Run(this, spriteSheets.GetSlimeDecal(), spriteSheets.GetDialougeBoxDecal());
			break;
		}
		case State::States::PLAY:
		{
			DrawDecal({ 0.0f, 0.0f }, spriteSheets.GetGameBackgroundDecal());
			SetPixelMode(olc::Pixel::MASK);
			break;
		}
		case State::States::ABOUTPAGE:
		{
			DrawDecal({ 0.0f, 0.0f }, spriteSheets.GetGameBackgroundDecal());
			SetPixelMode(olc::Pixel::MASK);
			break;
		}
		}
		return true;
	}

private:
	HomePage homePage{};
	SpriteSheets spriteSheets{};
	Dialouge dialouge{};
	Script script{};
};

int main()
{
	Application app{};
	if (app.Construct(600, 600, 1, 1))
	{
		app.Start();
	}
}