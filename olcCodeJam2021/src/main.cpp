#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "homePage.h"
#include "resource.h"

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
		Clear({ 255,228,196 });
		SetPixelMode(olc::Pixel::MASK);
		homePage.Run(this, elapsedTime, spriteSheets.GetSlimeDecal(), spriteSheets.GetWallDecal());
		
		return true;
	}

private:
	HomePage homePage{};
	SpriteSheets spriteSheets{};
};

int main()
{
	Application app{};
	if (app.Construct(600, 600, 1, 1))
	{
		app.Start();
	}
}