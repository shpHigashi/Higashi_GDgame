#pragma once
#include "Vec2.h"

// �v���C���[�N���X
class PlayerBase
{
public:
	PlayerBase();
	virtual ~PlayerBase() {}

	// �v���C���[�̏�����
	virtual void init();
	// �v���C���[�̉摜�Z�b�g
	virtual void setHandle(int playerHandle);
	// �v���C���[�̍��W�ݒ�
	virtual void setPos(float x, float y);
 
	// �v���C���[�̍X�V����
	virtual void update();
	// �v���C���[�̕`�揈��
	virtual void draw();

	// �v���C���[�̒��S���W�擾
	virtual float getCenterX() { return m_pos.x + (m_width / 2); }
	virtual float getCenterY() { return m_pos.y + (m_height / 2); }

	// m_isDead �� true �ɂ���
	virtual void setDead() { m_isDead = true; }
	// m_isDead ���擾
	virtual bool isDead() { return m_isDead; }

	// �����蔻��p�Ɏl�����̍��W�擾�@
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_width); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_height); }

	// �v���C���[�̍��W�擾
	Vec2 getPos() const { return m_pos; }

protected:
	// �摜�f�[�^
	int m_handle;

	// �摜�T�C�Y
	float m_height;
	float m_width;

	// �\���ʒu
	Vec2 m_pos;

	// �ړ���
	Vec2 m_vec;

	// ��]�p�x
	float m_angle;

	// ���S����
	bool m_isDead;
};