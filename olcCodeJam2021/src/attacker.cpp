#include "attacker.h"
#include "character.h"
#include "renderer.h"

Bullet::Bullet(const olc::vf2d& from, const olc::vf2d& to) :
	position{ from },
	from{ from }, to{ to },
	unitDir{ (to - from).norm() }
{
}

void Bullet::Shoot(olc::PixelGameEngine* pge, float speed) noexcept
{
	position += unitDir * speed * pge->GetElapsedTime();
}

AttackInterface::AttackInterface() = default;

void AttackInterface::Attack(olc::PixelGameEngine* pge) noexcept
{
	for (auto& bullet : bullets) bullet.Shoot(pge, 1200.0f);
}


PlayerAttacker::PlayerAttacker() = default;

void PlayerAttacker::RenderBullet(olc::PixelGameEngine* pge, olc::Decal* spriteSheet) noexcept
{
	for (auto& bullet : bullets) DrawBullet(bullet.position, pge, spriteSheet, true);
}

void PlayerAttacker::AddBullet(olc::PixelGameEngine* pge, const Character& player) noexcept
{
	if (pge->GetMouse(0).bReleased) bullets.push_back(Bullet{ player.position, (olc::vf2d)pge->GetMousePos() });
}
