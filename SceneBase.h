#pragma once

// �Q�[���V�[�����N���X
class SceneBase
{
public:
	SceneBase() {}
	virtual ~SceneBase() {}

	// ������
	virtual void init() {}
	// �폜
	virtual void end() {}
	// �X�V
	virtual void update() {}
	// �`��
	virtual void draw() {}

	// �V�[���I��
	virtual bool isEnd() { return false; }
};