#pragma once

#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneClear.h"

class SceneManager
{
public:
	// �V�[���̎�ޒ�`
	typedef enum SceneKind
	{
		kSceneKindTitle,
		kSceneKindMain,
		kSceneKindClear,

		kSceneKindNum
	}SceneKind;

public:
	SceneManager();
	virtual ~SceneManager();

	// ������
	void init(SceneKind kind = kSceneKindTitle);
	// �폜
	void end();

	// �X�V
	void update();
	// �`��
	void draw();

	// m_isMusicEnd ���擾
	bool isGameMusicEnd() { return m_isMusicEnd; }

private:
	// �Q�[���I��
	bool m_isMusicEnd;

	SceneKind	m_kind;

	SceneTitle	m_title;
	SceneMain	m_main;
	SceneClear	m_clear;

	PlayerCube m_player;
};