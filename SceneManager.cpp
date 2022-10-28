#include "SceneManager.h"
#include <cassert>

SceneManager::SceneManager()
{
	// �^�C�g���̃V�[������\��
	m_kind = kSceneKindTitle;

	// �Q�[���I��
	m_isMusicEnd = false;
}
SceneManager::~SceneManager()
{

}

// ������
void SceneManager::init(SceneKind kind)
{
	// �e�V�[���̏�����
	m_kind = kind;
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.init();	// �V�[���^�C�g���̏�����
		break;
	case SceneManager::kSceneKindMain:
		m_main.init();	// �V�[�����C���̏�����
		break;
	case SceneManager::kSceneKindClear:
		m_clear.init();	// �V�[���N���A�̏�����
		break;
	case SceneManager::kSceneKindNum:
	default:
		assert(false);
		break;
	}
}

// �폜
void SceneManager::end()
{
	// �e�V�[���̃f�[�^�폜
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.end();	// �V�[���^�C�g���̃f�[�^�폜
		break;
	case SceneManager::kSceneKindMain:
		m_main.end();	// �V�[�����C���̃f�[�^�폜
		break;
	case SceneManager::kSceneKindClear:
		m_clear.end();	// �V�[���N���A�̃f�[�^�폜
		break;
	case SceneManager::kSceneKindNum:
	default:
		assert(false);
		break;
	}
}

// �X�V
void SceneManager::update()
{
	// ���݂̃V�[���̍X�V���������s����
	bool isEnd = false;
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.update();	// �V�[���^�C�g���̍X�V
		isEnd = m_title.isEnd();
		break;
	case SceneManager::kSceneKindMain:
		m_main.update();	// �V�[�����C���̍X�V
		isEnd = m_main.isEnd();
		break;
	case SceneManager::kSceneKindClear:
		m_clear.update();	// �V�[���N���A�̍X�V
		isEnd = m_clear.isEnd();
		break;
	case SceneManager::kSceneKindNum:
	default:
		assert(false);
		break;
	}

	// isEnd �� true �̂Ƃ��A�e�V�[���̏������ƃf�[�^�폜���s��
	if (isEnd)
	{
		switch (m_kind)
		{
		case SceneManager::kSceneKindTitle:
			m_title.end();	// �V�[���^�C�g���̃f�[�^�폜
			m_main.init();	// �V�[�����C���̏�����
			m_kind = kSceneKindMain;
			break;
		case SceneManager::kSceneKindMain:
			// m_isGameClear �� true �̏ꍇ�A�Q�[���N���A�̃V�[�������������I��
			if (m_main.isGameClear())
			{
				m_isMusicEnd = true;
				m_main.end();	// �V�[�����C���̃f�[�^�폜
				m_clear.init();	// �V�[���N���A�̏�����
				m_kind = kSceneKindClear;
				break;
			}
			else // ����ȊO�̏ꍇ�A�^�C�g���̃V�[�������������I��
			{
				m_main.end();	// �V�[�����C���̃f�[�^�폜
				m_title.init();	// �V�[���^�C�g���̏�����
				m_kind = kSceneKindTitle;
				break;
			}
		case SceneManager::kSceneKindClear:	// �V�[�����Q�[���N���A�̏ꍇ�A�Q�[���I��
			m_isMusicEnd = false;
			m_clear.end();	// �V�[���N���A�̃f�[�^�폜
			m_title.init();	// �V�[���^�C�g���̏�����
			m_kind = kSceneKindTitle;
			break;
		case SceneManager::kSceneKindNum:
		default:
			assert(false);
			break;
		}
	}
}

// �`��
void SceneManager::draw()
{
	// ���݂̃V�[���̕`�揈�����s��
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.draw();	// �V�[���^�C�g���̕`��
		break;
	case SceneManager::kSceneKindMain:
		m_main.draw();	// �V�[�����C���̕`��
		break;
	case SceneManager::kSceneKindClear:
		m_clear.draw();	// �V�[���N���A�̕`��
		break;
	case SceneManager::kSceneKindNum:
	default:
		assert(false);
		break;
	}
}