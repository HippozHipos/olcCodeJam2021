#pragma once
#include "olcPixelGameEngine.h"

class Character;
class ControllerInterface
{
public:
	ControllerInterface();

public:
	virtual void Control(olc::PixelGameEngine* pge, Character& character) = 0;
};

class PlayerController : public ControllerInterface
{
public:
	PlayerController();

public:
	void Control(olc::PixelGameEngine* pge, Character& character) override;

private:
	float speed = 150.0f;
};

class BackAndForthController : public ControllerInterface
{
public:
	BackAndForthController(const olc::vf2d& p1, const olc::vf2d& p2);

public:
	void Control(olc::PixelGameEngine* pge, Character& character) override;

private:
	float speed = 1.0f;
	float angle = 0.0f;
	olc::vf2d unitDir;
	float totalDistance{};
	olc::vf2d p1;
	olc::vf2d p2;
};

class CircleController : public ControllerInterface
{
public:
	CircleController(float radius);

private:
	float radius;
};