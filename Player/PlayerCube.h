#pragma once

#include "Vec2.h"
#include "PlayerBase.h"

class PlayerCube : PlayerBase
{
public:
	PlayerCube();
	~PlayerCube() {}

	// プレイヤーの初期化
	void init();
	// プレイヤーの画像セット
	void setHandle(int playerHandle);
	// プレイヤーの座標設定
	void setPos(float x, float y);

	// プレイヤーの更新処理
	void update();
	// プレイヤーの描画処理
	void draw();
};