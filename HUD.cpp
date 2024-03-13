#include "HUD.h"

HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"),enemyNum_(3)
{
}

void HUD::Initialize()
{
	pText_ = new Text;
	pText_->Initialize();
}

void HUD::Update()
{

}

void HUD::Draw()
{
	pText_->Draw(30, 30, enemyNum_);
}

void HUD::Release()
{
	pText_->Release();
}
