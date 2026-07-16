#pragma once

#include <KamataEngine.h>

using namespace KamataEngine;

class Stage {
public:
	~Stage();

	void Initialize(Model* model);
	void Update();
	void Draw(const Camera& camera);

private:
	static const int kMapWidth = 20;
	static const int kMapHeight = 12;

	int mapData_[kMapHeight][kMapWidth];

	// ブロックモデル
	Model* model_ = nullptr;

	// 各ブロックのワールド変換
	WorldTransform worldTransform_[kMapHeight][kMapWidth];
};