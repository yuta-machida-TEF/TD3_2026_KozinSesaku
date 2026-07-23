#pragma once
#include "Player.h"
#include "Stage.h"
#include"Enemy.h"
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
	Model* modelBlock_ = nullptr;

	// オブジェクト
	Player* player_ = nullptr;

	Enemy* enemy_ = nullptr;

	Stage* stage_ = nullptr;

	// カメラ
	Camera camera_;

};