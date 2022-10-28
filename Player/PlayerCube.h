#pragma once

#include "Vec2.h"
#include "PlayerBase.h"

class PlayerCube : PlayerBase
{
public:
	PlayerCube();
	~PlayerCube() {}

	// �v���C���[�̏�����
	void init();
	// �v���C���[�̉摜�Z�b�g
	void setHandle(int playerHandle);
	// �v���C���[�̍��W�ݒ�
	void setPos(float x, float y);

	// �v���C���[�̍X�V����
	void update();
	// �v���C���[�̕`�揈��
	void draw();
};