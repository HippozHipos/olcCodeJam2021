#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "button.h"
#include "state.h"
#include "renderer.h"

class Application : public olc::PixelGameEngine
{
public:
	Application() { sAppName = "OlcCodeJam 2021 Entry - Thinking of a name..."; }

public:
	bool OnUserCreate() override
	{
		buttonSprite = std::make_unique<olc::Sprite>("resources\\button sprite sheet.png");
		buttonDecal = std::make_unique<olc::Decal>(buttonSprite.get());
		button = Button({ 50.0f, 50.0f }, "Start Game", buttonDecal.get(), State::States::PLAY);
		return true;
	}

	bool OnUserUpdate(float elapsedTime) override
	{
		Clear(olc::WHITE);
		SetPixelMode(olc::Pixel::MASK);
		DrawButton(this, button);
		DrawButtonText(this, button);
		//DrawSprite({ 0, 0 }, buttonSprite.get());

		return true;
	}

private:
	Button button;
	std::unique_ptr<olc::Sprite> buttonSprite;
	std::unique_ptr<olc::Decal> buttonDecal;
};

int main()
{
	Application app{};
	if (app.Construct(600, 600, 1, 1))
	{
		app.Start();
	}
}