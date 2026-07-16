#include "GameScene.h"

using namespace KamataEngine;

// デストラクタ
GameScene::~GameScene() {
	delete player_;
	delete modelPlayer_;
}

// 初期化
void GameScene::Initialize() {

	// 3Dモデルの生成
	modelPlayer_ = Model::CreateFromOBJ("player");

	// カメラの初期化
	camera_.translation_ = {0, 0, -20};
	camera_.Initialize();

	player_ = new Player();
	player_->Initialize(modelPlayer_);
}

// 更新
void GameScene::Update() 
{
	player_->Update();
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

	// 3Dモデル描画後処理
	Model::PostDraw();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	// スプライト描画後処理
	Sprite::PostDraw();
}