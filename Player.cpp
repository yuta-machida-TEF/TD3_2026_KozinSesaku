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

bool Player::CheckLanding(const KamataEngine::WorldTransform& platform, const KamataEngine::Vector3& platformSize, float previousBottom) {

	// プレイヤーの大きさ
	const float playerHalfWidth = 0.5f;
	const float playerHeight = 2.0f;

	// 現在のプレイヤーの足元
	float currentBottom = worldTransform_.translation_.y - playerHeight / 2.0f;

	// プレイヤーの左右
	float playerLeft = worldTransform_.translation_.x - playerHalfWidth;

	float playerRight = worldTransform_.translation_.x + playerHalfWidth;

	// 足場の左右
	float platformLeft = platform.translation_.x - platformSize.x / 2.0f;

	float platformRight = platform.translation_.x + platformSize.x / 2.0f;

	// 足場の上面
	float platformTop = platform.translation_.y + platformSize.y / 2.0f;

	// X方向で重なっているか
	bool overlapX = playerRight > platformLeft && playerLeft < platformRight;

	// 足場の上面を通過したか
	bool crossedPlatform = previousBottom >= platformTop && currentBottom <= platformTop;

	// 落下中か
	bool falling = velocity_.y < 0.0f;

	if (overlapX && crossedPlatform && falling) {

		// 足場の上に配置
		worldTransform_.translation_.y = platformTop + playerHeight / 2.0f;

		// 落下停止
		velocity_.y = 0.0f;

		// 接地状態
		isGround_ = true;

		return true;
	}

	return false;
}

// 更新
void Player::Update(const KamataEngine::WorldTransform& platform, const KamataEngine::Vector3& platformSize) {

	//====================
	// 移動入力
	//====================

	// 右移動
	if (Input::GetInstance()->PushKey(DIK_RIGHT)) {
		worldTransform_.translation_.x += moveSpeed_;
	}

	// 左移動
	if (Input::GetInstance()->PushKey(DIK_LEFT)) {
		worldTransform_.translation_.x -= moveSpeed_;
	}

	//====================
	// プレイヤーの足元を保存
	//====================

	const float playerHeight = 2.0f;

	float previousBottom = worldTransform_.translation_.y - playerHeight / 2.0f;

	//====================
	// ジャンプ
	//====================

	if (Input::GetInstance()->TriggerKey(DIK_UP) && isGround_) {

		velocity_.y = jumpPower_;

		isGround_ = false;
	}

	//====================
	// 重力
	//====================

	velocity_.y += gravity_;

	worldTransform_.translation_.y += velocity_.y;

	//====================
	// 足場との判定
	//====================

	CheckLanding(platform, platformSize, previousBottom);

	//====================
	// 地面判定
	//====================

	if (worldTransform_.translation_.y <= groundY) {

		worldTransform_.translation_.y = groundY;

		velocity_.y = 0.0f;

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