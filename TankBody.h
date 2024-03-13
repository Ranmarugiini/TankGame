#pragma once
#include "Engine/GameObject.h"

class TankBody : public GameObject
{
	int hModel_;
public:
	TankBody(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

private:
	void Move(XMVECTOR dir, float speed);
};

