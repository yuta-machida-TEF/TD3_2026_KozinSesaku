#include "Player.h"
#include<math/MathUtility.h>

using namespace KamataEngine;
using namespace MathUtility;

// 初期化
void Player::Initialize(Model* model) {
	model_ = model;
	worldTransform_.Initialize();

	// 初期回転
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;
	worldTransform_.translation_ = {-12.0f, -5.0f, 0};
}

// 更新
void Player::Update() {
	//====================
	// 移動入力
	//====================
	 
	//====================
	//右移動
	//====================
	if (Input::GetInstance()->PushKey(DIK_RIGHT)) {
		worldTransform_.translation_.x += 0.1f;
	}
	//====================
	//左移動
	//====================
	if (Input::GetInstance()->PushKey(DIK_LEFT)) {
		worldTransform_.translation_.x -= 0.1f;
	}
	//====================
	//ジャンプ
	//====================
	if (Input::GetInstance()->TriggerKey(DIK_UP) && isGround_)
	{
			velocityY_ = jumpPower_;
			isGround_ = false;
	}

	//====================
	// 重力計算
	//====================
	velocityY_ += gravity_;
	worldTransform_.translation_.y += velocityY_;

	//====================
	// 重力判定
	//====================
	if (worldTransform_.translation_.y <= groundY) {
	 worldTransform_.translation_.y = groundY;
	 velocityY_ = 0.0f;
	}

	//====================
	// 地面判定
	//====================
	if (worldTransform_.translation_.y <= groundY) {
	 worldTransform_.translation_.y = groundY;
	 velocityY_ = 0.0f;
	 isGround_ = true;
	}


	//====================
	// 範囲制限
	//====================
	if (worldTransform_.translation_.x > 13.0f) {
		worldTransform_.translation_.x = 13.0f;
	}
	if (worldTransform_.translation_.x < -14.0f) {
		worldTransform_.translation_.x = -14.0f;
	}
	if (worldTransform_.translation_.y > 7.0f) {
		worldTransform_.translation_.y = 7.0f;
	}
	if (worldTransform_.translation_.y < -7.0f) {
		worldTransform_.translation_.y = -7.0f;
	}

	worldTransform_.UpdateMatrix();
}

// 描画
void Player::Draw(Camera& camera) { model_->Draw(worldTransform_, camera); }