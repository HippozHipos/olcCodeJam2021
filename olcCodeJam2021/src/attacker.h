#pragma once
#include "olcPixelGameEngine.h"

class Bullet
{
public:
	Bullet(const olc::vf2d& from, const olc::vf2d& to);
	void Shoot(olc::PixelGameEngine* pge, float speed) noexcept;

public:
	olc::vf2d position{};
	olc::vf2d from{};
	olc::vf2d to{};
	olc::vf2d unitDir{};
};

class Character;
class AttackInterface
{
public:
	AttackInterface();

public:
	virtual void AddBullet(olc::PixelGameEngine* pge, const Character& character) noexcept = 0;
	virtual void RenderBullet(olc::PixelGameEngine* pge, olc::Decal* spriteSheet) noexcept = 0;
	void Attack(olc::PixelGameEngine* pge) noexcept;
	
protected:
	std::vector<Bullet> bullets;
};

class PlayerAttacker : public AttackInterface
{
public:
	PlayerAttacker();

public:
	void AddBullet(olc::PixelGameEngine* pge, const Character& player) noexcept override;
	void RenderBullet(olc::PixelGameEngine* pge, olc::Decal* spriteSheet) noexcept;
};
