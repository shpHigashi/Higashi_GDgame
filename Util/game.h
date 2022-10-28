#pragma once

namespace Game
{
	// ウィンドウモード設定
	constexpr bool kWindowMode = true;
	// ウィンドウ名
	const char* const kTitleText = "Gxxxxxy Dxxh";
	// ウィンドウサイズ
	constexpr int kScreenWidth = 1280;
	constexpr int kScreenHeight = 720;
	constexpr int kScreenWidthHalf = kScreenWidth / 2;
	constexpr int kScreenHeightHalf = kScreenHeight / 2;

	// ゲームのステージサイズ
	constexpr int kStageLowerLimit = 620;

	// カラーモード
	constexpr int kColorDepth = 32;
}