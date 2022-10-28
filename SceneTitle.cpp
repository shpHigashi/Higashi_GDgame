#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// �^�C�g�����b�Z�[�W
	const char* const kTitleMessage = "Z�L�[ or A�{�^����������";
	const char* const kGameStart = "�X�^�[�g";
}

// ������
void SceneTitle::init()
{
	// �摜�f�[�^�̓ǂݍ���
	// �Q�[���^�C�g��
	m_hGameLogo = LoadGraph("imagedata/VVVVVV_logo.png");
	GetGraphSize(m_hGameLogo, &m_width, &m_height);
	// �w�i�摜
	//m_hBackgroundGraphic = LoadGraph(Game::kBackgroundGraph);

	// �e�L�X�g���W��������
	m_TextPosY = 0;
	m_TextVecY = 4;

	// �V�[���I���� false ����
	m_isEnd = false;

}

// �I������
void SceneTitle::end()
{
	// �摜�f�[�^�폜
	DeleteGraph(m_hGameLogo);
	DeleteGraph(m_hCharaGraphic);
	DeleteGraph(m_hBackgroundGraphic);
}

// �X�V����
void SceneTitle::update()
{
	// �����̈ړ�
	m_TextPosY += m_TextVecY;

	// ��ʒ[�ɍs�����ꍇ�A�ړ��������t�ɕύX
	if (m_TextPosY < 0)
	{
		m_TextPosY = 0;
		m_TextVecY *= -1;
	}
	if (m_TextPosY > Game::kScreenHeight - m_height)
	{
		m_TextPosY = Game::kScreenHeight - m_height;
		m_TextVecY *= -1;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	// �L�[���͂��������ꍇ�A�V�[���I���� true �ɂ���
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}
}

// �`�揈��
void SceneTitle::draw()
{
	// �w�i�摜��ǂݍ���ŕ\��
	DrawGraph(0, 0, m_hBackgroundGraphic, true);

	// �Q�[���^�C�g���̉摜�\��
	DrawGraph(0, m_TextPosY, m_hGameLogo, true);
	DrawGraph(Game::kScreenWidth - m_width, m_TextPosY, m_hGameLogo, true);

	DrawRotaGraphF(Game::kScreenWidthHalf, Game::kScreenHeight / 3, 1.5, 0, m_hGameLogo, true, false);

	// �t�H���g�T�C�Y�̐ݒ�
	SetFontSize(30);
	// �^�C�g���̃e�L�X�g��\��
	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kTitleMessage, 12), Game::kScreenHeight / 2, kTitleMessage, GetColor(255, 255, 255));
	DrawString(Game::kScreenWidth / 2 - GetDrawStringWidth(kGameStart, 4), Game::kScreenHeight / 2 + 30, kGameStart, GetColor(255, 255, 255));
}