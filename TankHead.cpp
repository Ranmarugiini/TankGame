#include "TankHead.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent,"TankHead")
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("TankHead.fbx");
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_RIGHT)) {
		transform_.rotate_.y += 2.f;
	}

	if (Input::IsKey(DIK_LEFT)) {
		transform_.rotate_.y -= 2.f;
	}

	if (Input::IsKeyDown(DIK_SPACE)) {
		Shot();
	}
}

void TankHead::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}

void TankHead::Shot()
{
	// �e�ۂ𐶐�
	Bullet* b = Instantiate<Bullet>(GetParent()->GetParent());
	
	// ���˕�����ݒ肷��
	XMFLOAT3 top = Model::GetBonePosition(hModel_, "Top");
	XMFLOAT3 root = Model::GetBonePosition(hModel_, "Root");
	XMVECTOR dir = XMLoadFloat3(&top) - XMLoadFloat3(&root);

	// ���ˑ��x��ݒ肷��
	float speed = 0.2f;

	// ���ˈʒu��ݒ�
	b->SetPosition(top);

	// �ړ�
	XMFLOAT3 move{};
	XMStoreFloat3(&move, XMVector3Normalize(dir) * speed);
	b->SetMove(move);
}
