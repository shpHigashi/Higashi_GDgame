#pragma once
#include "SceneBase.h"

class SceneClear : public SceneBase
{
public:
	SceneClear()
	{
		titleDelay = 0;

		m_isEnd = false;

		m_clearSound = -1;

		m_hClearTextGraphic = -1;
		m_hBackgroundGraphic = -1;

		m_width = 0;
		m_height = 0;
	}
	virtual ~SceneClear() {}

	// ������
	virtual void init();

	// �I������
	void end();
	// �X�V
	virtual void update();
	// �`��
	virtual void draw();

	// m_isEnd ���擾
	virtual bool isEnd() { return m_isEnd; }
private:
	// �^�C�g���\���܂ł̒x���p�ϐ�
	int titleDelay;

	// �V�[���I��
	bool m_isEnd;

	// ���f�[�^
	int m_clearSound;

	// �摜�f�[�^
	int m_hClearTextGraphic;
	int m_hBackgroundGraphic;

	// �摜�T�C�Y
	int m_width;
	int m_height;
};