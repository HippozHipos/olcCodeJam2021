#include "application.h" 

Application::Application(){ sAppName = "OlcCodeJam 2021 Entry - Time lag"; }

bool Application::OnUserCreate() 
{
	spriteSheets.Load();
	spriteSheets.MakeDecalsFromSprites();
	homePage.Init(spriteSheets.GetButtonDecal());
	game.Init(spriteSheets.GetSlimeDecal());
	return true;
}

bool Application::OnUserUpdate(float elapsedTime)
{
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
		game.Run(this);
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