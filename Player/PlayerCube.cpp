#include "PlayerCube.h"
#include "DxLib.h"
#include "game.h"

namespace
{
    // 移動速度
    constexpr float kMoveSpeed = 12.0f;
    
    // 画像の回転速度
    constexpr float kRotaSpeed = 0.2f;

    // 画像の表示位置
    constexpr float kPlayerDrawPosX = 16.0f;
    constexpr float kPlayerDrawPosY = 34.0f;

    // ジャンプ力
    constexpr float kJumpAcc = -24.0f;

    // 重力
    constexpr float kGravity = 2.0f;
}

PlayerCube::PlayerCube()
{

}

// プレイヤーの初期化
void PlayerCube::init()
{
    m_pos.x = Game::kScreenWidthHalf;
    m_vec.x = kMoveSpeed;
}

// プレイヤーの画像セット
void PlayerCube::setHandle(int playerHandle)
{
	m_handle = playerHandle;
	GetGraphSizeF(m_handle, &m_width, &m_height);
}

// プレイヤーの座標設定
void PlayerCube::setPos(float x, float y)
{

}

// プレイヤーの更新処理
void PlayerCube::update()
{
    m_pos += m_vec;
    m_vec.y += kGravity;
    m_angle += kRotaSpeed;

    // 地面との当たり判定
    bool isField = false;

    if (m_pos.y > Game::kStageLowerLimit - m_height)
    {
        m_angle = 0;
        m_pos.y = Game::kStageLowerLimit - m_height;
        isField = true;
    }

    // パッド(もしくはキーボード)からの入力を取得する
    int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
    if (padState & PAD_INPUT_1)
    {
        if (isField)
        {
            m_vec.y = kJumpAcc;	// ジャンプ開始
        }
    }

    // 画面端に行こうとした場合
    if (getLeft() < 0)
    {
        m_pos.x = 0.0f;    // 画面端より左には行かない
        m_vec.x *= -1;
    }
    if (getRight() > Game::kScreenWidth)
    {
        m_pos.x = static_cast<float>(Game::kScreenWidth - m_width); // 画面端より右には行かない
        m_vec.x *= -1;
    }
    // ステージの範囲外に行こうとした場合
    if (getBottom() > Game::kStageLowerLimit)
    {
        m_pos.y = static_cast<float>(Game::kStageLowerLimit - m_height);    // ステージの範囲より下には行かない
    }
}

// プレイヤーの描画処理
void PlayerCube::draw()
{
	DrawRotaGraph(getCenterX(), getCenterY(), 1, m_angle, m_handle, true, false);
    DrawBox(m_pos.x, m_pos.y, getRight(), getBottom(), GetColor(255, 255, 255), false);
}