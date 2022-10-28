#pragma once

#include "PlayerCube.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	void update();
	// ���t���[���̕`��
	void draw();
	// �����蔻��`�F�b�N����
	void checkCollision();

	// �G�̐���
	void createEnemyRight();
	void createEnemyLeft();

	// m_isGameClear���擾
	virtual bool isGameClear() { return m_isGameClear; }
	// m_isEnd���擾
	virtual bool isEnd() { return m_isEnd; }

private:
	// �Б��̓G�̍ő�o����
	static constexpr int kEnemyMax = 10;

private:
	// ��x�����Đ�
	bool m_playOnceOnly;

	// �w�i�̃O���t�B�b�N�n���h��
	int m_hBackgroundGraphic;
	// �L�����N�^�[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	int m_hPlayerDeadGraphic;
	// �G�̃O���t�B�b�N�n���h��
	int m_hEnemyGraphic;

	// �t�H���g�T�C�Y
	int m_fontSize;

	// �Q�[���I�[�o�[���̒x������
	int m_GameOverDelay;
	// �G�̏o���x��
	int m_spawnDelay;

	// �Q�[���N���A
	bool m_isGameClear;

	// �V�[���I��
	bool m_isEnd;

	// �v���C���[
	PlayerCube m_player;

	// �G
};