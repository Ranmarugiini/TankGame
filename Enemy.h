#pragma once
#include "Engine/GameObject.h"
#include "Engine/BoxCollider.h"

class Enemy : public GameObject
{
	int hModel_;

public:
	Enemy(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	//‰½‚©‚É“–‚½‚Á‚½
	//ˆø”FpTarget “–‚½‚Á‚½‘Šè
	void OnCollision(GameObject* pTarget) override;
};

