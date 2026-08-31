#pragma once
#include "Enemy.h"
#include "Enemy2.h"
#include "Player.h"
#include "Stage.h"
#include <KamataEngine.h>

using namespace KamataEngine;

class GameScene {
public:
	// デストラクタ
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();


private:
	// 3Dモデル
	Model* modelPlayer_ = nullptr;
	Model* modelEnemy_ = nullptr;
	Model* modelEnemy2_ = nullptr;
	Model* modelBlock_ = nullptr;

	// オブジェクト
	Player* player_ = nullptr;

	Enemy* enemy_ = nullptr;

	Enemy2* enemy2_ = nullptr;

	Stage* stage_ = nullptr;

	// カメラ
	Camera camera_;

	float previousBottom = 0.0f;

	Vector3 previousPosition = {-15.0f, 8.0f, 0.0f};
};