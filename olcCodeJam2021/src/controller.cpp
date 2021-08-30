#include "controller.h"
#include "character.h"

ControllerInterface::ControllerInterface() = default;

PlayerController::PlayerController() = default;

void PlayerController::Control(olc::PixelGameEngine* pge, Character& character)
{
	if (pge->GetKey(olc::A).bHeld) character.position.x -= pge->GetElapsedTime() * speed;
	if (pge->GetKey(olc::D).bHeld) character.position.x += pge->GetElapsedTime() * speed;
	if (pge->GetKey(olc::S).bHeld) character.position.y += pge->GetElapsedTime() * speed;
	if (pge->GetKey(olc::W).bHeld) character.position.y -= pge->GetElapsedTime() * speed;
}

BackAndForthController::BackAndForthController(const olc::vf2d& p1, const olc::vf2d& p2) :
	p1{ p1 }, p2{ p2 }
{
	unitDir = (p2 - p1).norm();
	totalDistance = std::hypot(p1.x - p2.x, p1.y - p2.y);
}

void BackAndForthController::Control(olc::PixelGameEngine* pge, Character& character)
{
	float alpha = (std::cos(angle) + 1.0f) * 0.5f;
	angle += speed * pge->GetElapsedTime();
	float currentDistance = alpha * totalDistance;
	character.position = unitDir * currentDistance + p1;
}

CircleController::CircleController(float radius) : 
	radius{ radius }
{
}
