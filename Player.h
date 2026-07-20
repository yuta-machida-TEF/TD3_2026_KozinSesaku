#pragma once

#include <KamataEngine.h>
#include <numbers>

using namespace KamataEngine;

class Player {
public:
	// 初期化
	void Initialize(Model* model);

	// 更新
	void Update();

	// 描画
	void Draw(Camera& camera);

private:
	// モデル
	Model* model_ = nullptr;

	  // 落下速度
	float velocityY_ = 0.0f;

	// 重力
	const float gravity_ = -0.3f;

	  // 地面にいるか
	bool isGround_ = true;

	//地面の高さ
	const float groundY = -7.0f;

	// ジャンプ力
	const float jumpPower_ = 1.3f;


	// ワールド変換
	WorldTransform worldTransform_;
};