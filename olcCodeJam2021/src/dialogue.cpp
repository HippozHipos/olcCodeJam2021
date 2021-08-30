#include "dialogue.h"
#include "renderer.h"

DialougeBoxExtender::DialougeBoxExtender() = default;

float DialougeBoxExtender::GetExtendedX(olc::PixelGameEngine * pge) noexcept
{
	if (x < 0.001f)
	{
		return x += pge->GetElapsedTime() * speed;
	}
	return x;
}

bool DialougeBoxExtender::FinishedExtention() const noexcept
{
	return x > 0.0f;
}

DialougeManager::DialougeManager() = default;

void DialougeManager::IncrementDialougeOnSpacePress(olc::PixelGameEngine* pge, size_t scriptSize) noexcept
{
	if (pge->GetKey(olc::SPACE).bReleased)
	{
		if (currentDialouge < (int)scriptSize - 1) currentDialouge++;
		else State::SetCurrentState(State::States::PLAY);
	}
}

size_t DialougeManager::GetCurrentDialouge() const noexcept
{
	return currentDialouge;
}

BlinkingColor::BlinkingColor() = default;

olc::Pixel BlinkingColor::GetColor(olc::PixelGameEngine* pge, float speed) noexcept
{
	totalElapsedTime += pge->GetElapsedTime();
	float color = (std::sin(totalElapsedTime * speed) + 1.0f) * 0.5f * 150.0f;
	return { (uint8_t)color, (uint8_t)color, (uint8_t)color };
}

Dialouge::Dialouge() = default;

void Dialouge::Say(olc::PixelGameEngine* pge, olc::Decal* dialougeSpriteSheet) noexcept
{
	DrawDialougeBoxText(pge, script.GetScript()[manager.GetCurrentDialouge()]);
}

void Dialouge::DoSlimeAnimation(olc::PixelGameEngine* pge, olc::Decal* slimeSpriteSheet) noexcept
{
	if (GloosTurn())
	{
		SlimeAnimation::PartialDecalInfo info = slimeAnimation.GetPartialDecalInfo(pge->GetElapsedTime(), 15.0f, SlimeAnimation::Type::EYESLEFT);
		DrawSlimeAnimation(pge, { 500.0f, 345.0f }, slimeSpriteSheet, info);
	}
}

void Dialouge::DrawPressSpaceText(olc::PixelGameEngine* pge)
{
	pge->DrawStringDecal({ 10.0f, 10.0f }, "Press space to continue...", blinkingColor.GetColor(pge, 6.0f), { 1.8f, 1.8f });
}

void Dialouge::Run(olc::PixelGameEngine* pge, olc::Decal* slimeSpriteSheet, olc::Decal* dialougeSpriteSheet) noexcept
{
	DrawDialougeBox(boxAnimator.GetExtendedX(pge), pge, dialougeSpriteSheet, GloosTurn());
	DrawPressSpaceText(pge);
	if (boxAnimator.FinishedExtention())
	{
		manager.IncrementDialougeOnSpacePress(pge, script.GetScript().size());
		Say(pge, dialougeSpriteSheet);
		DoSlimeAnimation(pge, slimeSpriteSheet);
	}
}

bool Dialouge::GloosTurn() const noexcept
{
	if ((int)manager.GetCurrentDialouge() < 8)
	{
		return !(manager.GetCurrentDialouge() % 2 == 0);
	}
	return false;
}

