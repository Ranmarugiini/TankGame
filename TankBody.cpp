#include "TankBody.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "TankHead.h"
#include "Engine/Camera.h"

TankBody::TankBody(GameObject* parent)
	:GameObject(parent,"TankBody")
{
}

void TankBody::Initialize()
{
	hModel_ = Model::Load("TankBody.fbx");
	Instantiate<TankHead>(this);
	transform_.position_ = { -5,0,-5 };
}

void TankBody::Update()
{
	if (Input::IsKey(DIK_A)) {
		transform_.rotate_.y -= 2.f;
	}

	if (Input::IsKey(DIK_D)) {
		transform_.rotate_.y += 2.f;
	}

	// 方向を設定
	XMVECTOR dirction = { 0,0,1,0 }; 
		
	// 回転行列を生成
	XMMATRIX matRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));

	// 回転させる
	dirction = XMVector3Transform(dirction, matRotate);
	
	// 速度を設定
	float speed = 0.1f;

	// 移動
	if (Input::IsKey(DIK_W)) {
		Move(dirction, speed);
	}

	if (Input::IsKey(DIK_S)) {
		Move(-dirction, speed);
	}

}

void TankBody::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankBody::Release()
{
}

void TankBody::Move(XMVECTOR dir, float speed)
{
	XMVECTOR move = XMVector3Normalize(dir) * speed;
	XMStoreFloat3(&transform_.position_, XMLoadFloat3(&transform_.position_) + move);
}
