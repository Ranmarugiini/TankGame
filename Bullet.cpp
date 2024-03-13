#include "Bullet.h"
#include "Engine/Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent,"Bullet")
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("DebugCollision/SphereCollider.fbx");
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.3f);
	AddCollider(collision);
	transform_.scale_ = { 0.2f,0.2f ,0.2f };
}

void Bullet::Update()
{
    transform_.position_.x += move_.x;
    transform_.position_.y += move_.y;
    transform_.position_.z += move_.z;

    // ä»íPÇ»èdóÕèàóù
    move_.y -= 0.01f;

}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
