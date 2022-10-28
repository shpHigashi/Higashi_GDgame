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
	// ���S����
	bool m_isDead;

	// �v���C���[���W
	Vec2 m_pos;

	// �v���C���[�ړ���
	Vec2 m_vec;
};