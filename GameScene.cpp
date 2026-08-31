#include "GameScene.h"


using namespace KamataEngine;

// デストラクタ
GameScene::~GameScene() {
	delete player_;
	delete modelPlayer_;
	delete stage_;
	delete modelBlock_;
	delete modelEnemy_;
	delete modelEnemy2_;
}

// 初期化
void GameScene::Initialize() {

	// 3Dモデルの生成
	modelPlayer_ = Model::CreateFromOBJ("player");
	modelEnemy_ = Model::CreateFromOBJ("enemy");
	modelBlock_ = Model::CreateFromOBJ("block");
	modelEnemy2_ = Model::CreateFromOBJ("enemy");

	// カメラの初期化
	camera_.translation_ = {0, 0, -20};
	camera_.Initialize();

	player_ = new Player();
	player_->Initialize(modelPlayer_);

	enemy_ = new Enemy();
	enemy_->Initialize(modelEnemy_);

	enemy2_ = new Enemy2();
	enemy2_->Initialize(modelEnemy2_);

	stage_ = new Stage();
	stage_->Initialize(modelBlock_);
}


// 更新
void GameScene::Update() {

	player_->Update(stage_,enemy_,enemy2_);

	stage_->Update();


	enemy_->Update();

	enemy2_->Update();
}

// 描画
void GameScene::Draw() {
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	// スプライト描画後処理
	Sprite::PostDraw();

	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();
	// 3Dモデル描画前処理
	Model::PreDraw();

	// ここに3Dモデルインスタンスの描画処理を記述する
	player_->Draw(camera_);
	enemy_->Draw(camera_);
	enemy2_->Draw(camera_);
	stage_->Draw(camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	// スプライト描画後処理
	Sprite::PostDraw();
}