#include "DxLib.h"
#include "SceneMain.h"
#include "game.h"

namespace
{
	// 敵出現用の遅延時間
	constexpr int kSpawnDelay = 100;
	// 死亡時の遅延
	constexpr int kGameOverDelay = 90;
	// ゲームオーバー
	const char* const kGameOver = "GameOver";
	constexpr int kFontSize = 60;

	// 制限時間表示位置
	constexpr int kTimerPositionX = Game::kScreenWidthHalf - 30;
	constexpr int kTimerPositionY = Game::kStageLowerLimit + 25;

	// RGB初期値用
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

// 初期化
void SceneMain::init()
{
	// 一度だけ再生
	m_playOnceOnly = false;

	// 画像データの読み込み
	//m_hBackgroundGraphic = LoadGraph(Game::kBackgroundGraph);
	m_hPlayerGraphic = LoadGraph("imageData/PlayerCube.png");
	m_hEnemyGraphic = LoadGraph("imagedata/enemy.png");

	// プレイヤー画像と音の設定
	m_player.setHandle(m_hPlayerGraphic);

	// プレイヤーの初期位置設定
	m_player.setPos(Game::kScreenWidthHalf, Game::kScreenHeightHalf);
	// プレイヤー初期化 
	m_player.init();

	// フォントサイズ設定
	m_fontSize = kFontSize;

	// 各時間用変数の初期化
	m_spawnDelay = kSpawnDelay;
	m_GameOverDelay = kGameOverDelay;

	// シーン終了、ゲームクリアを false に初期化
	m_isGameClear = false;
	m_isEnd = false;
}

// 終了処理
void SceneMain::end()
{
	// 画像データの削除
	DeleteGraph(m_hBackgroundGraphic);
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hPlayerDeadGraphic);
	DeleteGraph(m_hEnemyGraphic);
}

// 毎フレームの処理
void SceneMain::update()
{
	// 背景の表示
	DrawGraph(0, 0, m_hBackgroundGraphic, true);

	// プレイヤーの死亡判定が true の場合
	//if (m_player.isDead())
	//{
	//	if (!m_playOnceOnly)
	//	{
	//		PlaySoundMem(m_deathSound, DX_PLAYTYPE_BACK);
	//		m_playOnceOnly = true;
	//	}
	//	// ゲームオーバー遅延を1フレームごとに減少させる
	//	m_GameOverDelay--;

	//	return;
	//}

	// 1フレームごとに残り時間と敵の出現遅延を減少させる
	m_spawnDelay--;

	// 出現遅延が0になった場合、敵を出現させる
	if (!m_spawnDelay)
	{
		// それぞれの方向の敵を作成
		createEnemyLeft();
		createEnemyRight();

		// 出現遅延に再び定数を代入
		m_spawnDelay = kSpawnDelay;
	}

	// プレイヤーの更新処理
	m_player.update();

	// 当たり判定チェック処理
	//checkCollision();
}

// 毎フレームの描画
void SceneMain::draw()
{
	// プレイヤーの描画
	m_player.draw();

	// ステージの線の表示
	DrawLine(0, Game::kStageLowerLimit, Game::kScreenWidth, Game::kStageLowerLimit, GetColor(255, 255, 255));

	// プレイヤーの死亡判定が true の場合
	//if (m_player.isDead())
	//{
	//	// 1フレームごとにフォントサイズを増加させる
	//	m_fontSize++;
	//	SetFontSize(m_fontSize);
	//	// ゲームオーバーのテキストを表示
	//	DrawString(Game::kScreenWidthHalf - GetDrawStringWidth(kGameOver, 4), 210, kGameOver, GetColor(255, 0, 0));
	//}
}

// 当たり判定チェック処理
void SceneMain::checkCollision()
{
	//for (auto& EnemyLeft : m_EnemyLeft)
	//{
	//	// 当たっていない場合処理をスキップ
	//	if (EnemyLeft.getRight() <= m_player.getLeft()) continue;
	//	if (m_player.getRight() <= EnemyLeft.getLeft()) continue;
	//	if (EnemyLeft.getBottom() <= m_player.getTop()) continue;
	//	if (m_player.getBottom() <= EnemyLeft.getTop()) continue;
	//	// 当たっている場合プレイヤーを死亡判定にする
	//	m_player.setDead();
	//}
	//for (auto& EnemyRight : m_EnemyRight)
	//{
	//	// 当たっていない場合処理をスキップ
	//	if (EnemyRight.getRight() <= m_player.getLeft()) continue;
	//	if (m_player.getRight() <= EnemyRight.getLeft()) continue;
	//	if (EnemyRight.getBottom() <= m_player.getTop()) continue;
	//	if (m_player.getBottom() <= EnemyRight.getTop()) continue;
	//	// 当たっている場合プレイヤーを死亡判定にする
	//	m_player.setDead();
	//}
}

// 敵の生成(左から出現)
void SceneMain::createEnemyLeft()
{
	
}
// 敵の生成(右から出現)
void SceneMain::createEnemyRight()
{
	
}