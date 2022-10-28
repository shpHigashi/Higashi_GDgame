#pragma once

#include "Vec2.h"

class PlayerBase
{
public:
	PlayerBase();
	virtual ~PlayerBase();

	virtual void setHandle();
	virtual void init();

	virtual void update();
	virtual void draw();

private:
	// 死亡判定
	bool m_isDead;

	// プレイヤー座標
	Vec2 m_pos;

	// プレイヤー移動量
	Vec2 m_vec;
};