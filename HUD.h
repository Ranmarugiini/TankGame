#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class HUD : public GameObject
{
	Text* pText_;
	int enemyNum_;
public:
	HUD(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	void SetEnemyNum(int num) { enemyNum_ = num; }
	int GetEnemyNum() { return enemyNum_; }
};

