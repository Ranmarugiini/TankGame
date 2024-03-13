#include "TestScene.h"
#include "TankBody.h"
#include "TankHead.h"
#include "Enemy.h"
#include "Engine/Camera.h"
#include "Engine/Global.h"
#include "HUD.h"
//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	HUD* hud = Instantiate<HUD>(this);
	int eNum = hud->GetEnemyNum();

	Camera::SetPosition(XMFLOAT3(0, 30, -20));

	Instantiate<TankBody>(this);
	
	for (int i = 0; i < eNum; i++) {
		Enemy* e = Instantiate<Enemy>(this);
		e->SetPosition(i * 5, 0, i*5);
	}

}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}
