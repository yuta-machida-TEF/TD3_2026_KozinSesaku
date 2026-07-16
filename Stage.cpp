#include "Stage.h"


void Stage::Initialize(Model* model) {

	model_ = model;

	for (int y = 0; y < kMapHeight; y++) {
		for (int x = 0; x < kMapWidth; x++) {

			worldTransform_[y][x].Initialize();

			worldTransform_[y][x].translation_ = {float(x * 2.0f), float(-y * 2.0f), 0.0f};

			worldTransform_[y][x].UpdateMatrix();
		}
	}
}

void Stage::Update()
{
}

void Stage::Draw(const Camera& camera) {
	for (int y = 0; y < kMapHeight; y++) {
		for (int x = 0; x < kMapWidth; x++) {

			if (mapData_[y][x] == 1) {

				model_->Draw(worldTransform_[y][x], camera);
			}
		}
	}
}
