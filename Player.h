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

	// ワールド変換
	WorldTransform worldTransform_;
};