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
	Vector2 velocity_ = {0.0f,0.0f};

	// 重力
	const float gravity_ = -0.020f;

	  // 地面にいるか
	bool isGround_ = true;

	//地面の高さ
	const float groundY = -7.0f;

	// ジャンプ力
	const float jumpPower_ = 0.38f;

	const float moveSpeed_ = 0.20f;


	// ワールド変換
	WorldTransform worldTransform_;
};