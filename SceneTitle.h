#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle()
	{
		m_TextPosY = 0;
		m_TextVecY = 0;

		m_isEnd = false;

		m_hGameLogo = -1;
		m_hCharaGraphic = -1;
		m_hBackgroundGraphic = -1;

		m_width = 0;
		m_height = 0;
	}
	virtual ~SceneTitle() {}

	// ������
	virtual void init();

	// �I������
	void end();

	// �X�V����
	virtual void update();
	// �`��
	virtual void draw();

	// m_isEnd ���擾
	virtual bool isEnd() { return m_isEnd; }
private:
	// �e�L�X�g�\���ʒu�ύX
	int m_TextPosY;
	int m_TextVecY;

	// �^�C�g���\�����I���邩�ǂ���
	bool m_isEnd;

	// �摜�f�[�^
	int m_hGameLogo;
	int m_hCharaGraphic;
	int m_hBackgroundGraphic;
	// �摜�T�C�Y
	int m_width;
	int m_height;
};