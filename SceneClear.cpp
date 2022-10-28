#include "SceneClear.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// �^�C�g���\���܂ł̒x������ (2�b)
	constexpr int kTitleDelayMax = 120;
}

// ������
void SceneClear::init()
{
	// �x�����ԏ�����
	titleDelay = kTitleDelayMax;

	m_isEnd = false;

	// ���f�[�^�̓ǂݍ���
	m_clearSound = LoadSoundMem("sounddata/stageclear.wav");
	PlaySoundMem(m_clearSound, DX_PLAYTYPE_BACK);

	// �摜�̓ǂݍ���
	m_hClearTextGraphic = LoadGraph("imagedata/GameClear.png");
	//m_hBackgroundGraphic = LoadGraph(Game::kBackgroundGraph);
	// �摜�T�C�Y�̎擾
	GetGraphSize(m_hClearTextGraphic, &m_width, &m_height);
}

// �I������
void SceneClear::end()
{
	// ���f�[�^�̍폜
	DeleteSoundMem(m_clearSound);

	// �摜�f�[�^�̍폜
	DeleteGraph(m_hClearTextGraphic);
	DeleteGraph(m_hBackgroundGraphic);
}

// �X�V
void SceneClear::update()
{
	// 1�t���[�����ƂɎc��x�����Ԃ����炷
	titleDelay--;
	// 0�ɂȂ�����V�[���I��
	if (!titleDelay)
	{
		m_isEnd = true;
	}
}

void SceneClear::draw()
{
	// �w�i�摜�̕`��
	DrawGraph(0, 0, m_hBackgroundGraphic, true);

	// �N���A�e�L�X�g�摜�̕\��
	DrawRotaGraphF(Game::kScreenWidthHalf, Game::kScreenHeightHalf, 1.5, 0, m_hClearTextGraphic, true, false);
}