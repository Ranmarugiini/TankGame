#pragma once
#include "Engine/GameObject.h"

class TankHead : public GameObject
{
	int hModel_;
public:
	TankHead(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

private:
	void Shot();
};

