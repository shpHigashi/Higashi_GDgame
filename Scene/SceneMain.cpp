#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"

namespace
{
	// �G�o���p�̒x������
	constexpr int kSpawnDelay = 100;
	// ���S���̒x��
	constexpr int kGameOverDelay = 90;
	// �Q�[���I�[�o�[
	const char* const kGameOver = "GameOver";
	constexpr int kFontSize = 60;

	// �������ԕ\���ʒu
	constexpr int kTimerPositionX = Game::kScreenWidthHalf - 30;
	constexpr int kTimerPositionY = Game::kStageLowerLimit + 25;

	// RGB�����l�p
	constexpr int kSetColor = 255;
}

SceneMain::SceneMain()
{
	m_playOnceOnly = false;

	m_hBackgroundGraphic = -1;
	m_hPlayerGraphic = -1;
	m_hPlayerDeadGraphic = -1;
	m_hEnemyGraphic = -1;

	m_spawnDelay = 0;
	m_fontSize = 0;

	m_GameOverDelay = kGameOverDelay;

	m_isGameClear = false;
	m_isEnd = false;
}
SceneMain::~SceneMain()
{
}

// ������
void SceneMain::init()
{
	// ��x�����Đ�
	m_playOnceOnly = false;

	// �摜�f�[�^�̓ǂݍ���
	//m_hBackgroundGraphic = LoadGraph(Game::kBackgroundGraph);
	m_hPlayerGraphic = LoadGraph("imageData/PlayerCube.png");
	m_hEnemyGraphic = LoadGraph("imagedata/enemy.png");

	// �v���C���[�摜�Ɖ��̐ݒ�
	m_player.setHandle(m_hPlayerGraphic);

	// �v���C���[�̏����ʒu�ݒ�
	m_player.setPos(Game::kScreenWidthHalf, Game::kScreenHeightHalf);
	// �v���C���[������ 
	m_player.init();

	// �t�H���g�T�C�Y�ݒ�
	m_fontSize = kFontSize;

	// �e���ԗp�ϐ��̏�����
	m_spawnDelay = kSpawnDelay;
	m_GameOverDelay = kGameOverDelay;

	// �V�[���I���A�Q�[���N���A�� false �ɏ�����
	m_isGameClear = false;
	m_isEnd = false;
}

// �I������
void SceneMain::end()
{
	// �摜�f�[�^�̍폜
	DeleteGraph(m_hBackgroundGraphic);
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hPlayerDeadGraphic);
	DeleteGraph(m_hEnemyGraphic);
}

// ���t���[���̏���
void SceneMain::update()
{
	// �w�i�̕\��
	DrawGraph(0, 0, m_hBackgroundGraphic, true);

	// �v���C���[�̎��S���肪 true �̏ꍇ
	//if (m_player.isDead())
	//{
	//	if (!m_playOnceOnly)
	//	{
	//		PlaySoundMem(m_deathSound, DX_PLAYTYPE_BACK);
	//		m_playOnceOnly = true;
	//	}
	//	// �Q�[���I�[�o�[�x����1�t���[�����ƂɌ���������
	//	m_GameOverDelay--;

	//	return;
	//}

	// 1�t���[�����ƂɎc�莞�ԂƓG�̏o���x��������������
	m_spawnDelay--;

	// �o���x����0�ɂȂ����ꍇ�A�G���o��������
	if (!m_spawnDelay)
	{
		// ���ꂼ��̕����̓G���쐬
		createEnemyLeft();
		createEnemyRight();

		// �o���x���ɍĂђ萔����
		m_spawnDelay = kSpawnDelay;
	}

	// �v���C���[�̍X�V����
	m_player.update();

	// �����蔻��`�F�b�N����
	//checkCollision();
}

// ���t���[���̕`��
void SceneMain::draw()
{
	// �v���C���[�̕`��
	m_player.draw();

	// �X�e�[�W�̐��̕\��
	DrawLine(0, Game::kStageLowerLimit, Game::kScreenWidth, Game::kStageLowerLimit, GetColor(255, 255, 255));

	// �v���C���[�̎��S���肪 true �̏ꍇ
	//if (m_player.isDead())
	//{
	//	// 1�t���[�����ƂɃt�H���g�T�C�Y�𑝉�������
	//	m_fontSize++;
	//	SetFontSize(m_fontSize);
	//	// �Q�[���I�[�o�[�̃e�L�X�g��\��
	//	DrawString(Game::kScreenWidthHalf - GetDrawStringWidth(kGameOver, 4), 210, kGameOver, GetColor(255, 0, 0));
	//}
}

// �����蔻��`�F�b�N����
void SceneMain::checkCollision()
{
	//for (auto& EnemyLeft : m_EnemyLeft)
	//{
	//	// �������Ă��Ȃ��ꍇ�������X�L�b�v
	//	if (EnemyLeft.getRight() <= m_player.getLeft()) continue;
	//	if (m_player.getRight() <= EnemyLeft.getLeft()) continue;
	//	if (EnemyLeft.getBottom() <= m_player.getTop()) continue;
	//	if (m_player.getBottom() <= EnemyLeft.getTop()) continue;
	//	// �������Ă���ꍇ�v���C���[�����S����ɂ���
	//	m_player.setDead();
	//}
	//for (auto& EnemyRight : m_EnemyRight)
	//{
	//	// �������Ă��Ȃ��ꍇ�������X�L�b�v
	//	if (EnemyRight.getRight() <= m_player.getLeft()) continue;
	//	if (m_player.getRight() <= EnemyRight.getLeft()) continue;
	//	if (EnemyRight.getBottom() <= m_player.getTop()) continue;
	//	if (m_player.getBottom() <= EnemyRight.getTop()) continue;
	//	// �������Ă���ꍇ�v���C���[�����S����ɂ���
	//	m_player.setDead();
	//}
}

// �G�̐���(������o��)
void SceneMain::createEnemyLeft()
{
	
}
// �G�̐���(�E����o��)
void SceneMain::createEnemyRight()
{
	
}