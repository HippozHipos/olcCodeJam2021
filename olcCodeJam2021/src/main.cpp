#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Application : public olc::PixelGameEngine
{
public:
	Application() { sAppName = "OlcCodeJam 2021 Entry - Thinking of a name..."; }

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float elapsedTime) override
	{
		return true;
	}
};

int main()
{
	Application app{};
	if (app.Construct(600, 600, 1, 1))
	{
		app.Start();
	}
}