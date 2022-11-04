#include "PlayerCube.h"
#include "DxLib.h"
#include "game.h"

namespace
{
    // �ړ����x
    constexpr float kMoveSpeed = 12.0f;
    
    // �摜�̉�]���x
    constexpr float kRotaSpeed = 0.2f;

    // �摜�̕\���ʒu
    constexpr float kPlayerDrawPosX = 16.0f;
    constexpr float kPlayerDrawPosY = 34.0f;

    // �W�����v��
    constexpr float kJumpAcc = -24.0f;

    // �d��
    constexpr float kGravity = 2.0f;
}

PlayerCube::PlayerCube()
{

}

// �v���C���[�̏�����
void PlayerCube::init()
{
    m_pos.x = Game::kScreenWidthHalf;
    m_vec.x = kMoveSpeed;
}

// �v���C���[�̉摜�Z�b�g
void PlayerCube::setHandle(int playerHandle)
{
	m_handle = playerHandle;
	GetGraphSizeF(m_handle, &m_width, &m_height);
}

// �v���C���[�̍��W�ݒ�
void PlayerCube::setPos(float x, float y)
{

}

// �v���C���[�̍X�V����
void PlayerCube::update()
{
    m_pos += m_vec;
    m_vec.y += kGravity;
    m_angle += kRotaSpeed;

    // �n�ʂƂ̓����蔻��
    bool isField = false;

    if (m_pos.y > Game::kStageLowerLimit - m_height)
    {
        m_angle = 0;
        m_pos.y = Game::kStageLowerLimit - m_height;
        isField = true;
    }

    // �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
    int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
    if (padState & PAD_INPUT_1)
    {
        if (isField)
        {
            m_vec.y = kJumpAcc;	// �W�����v�J�n
        }
    }

    // ��ʒ[�ɍs�����Ƃ����ꍇ
    if (getLeft() < 0)
    {
        m_pos.x = 0.0f;    // ��ʒ[��荶�ɂ͍s���Ȃ�
        m_vec.x *= -1;
    }
    if (getRight() > Game::kScreenWidth)
    {
        m_pos.x = static_cast<float>(Game::kScreenWidth - m_width); // ��ʒ[���E�ɂ͍s���Ȃ�
        m_vec.x *= -1;
    }
    // �X�e�[�W�͈̔͊O�ɍs�����Ƃ����ꍇ
    if (getBottom() > Game::kStageLowerLimit)
    {
        m_pos.y = static_cast<float>(Game::kStageLowerLimit - m_height);    // �X�e�[�W�͈̔͂�艺�ɂ͍s���Ȃ�
    }
}

// �v���C���[�̕`�揈��
void PlayerCube::draw()
{
	DrawRotaGraph(getCenterX(), getCenterY(), 1, m_angle, m_handle, true, false);
    DrawBox(m_pos.x, m_pos.y, getRight(), getBottom(), GetColor(255, 255, 255), false);
}