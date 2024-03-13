#pragma once
#include "Engine/GameObject.h"

class Bullet : public GameObject
{
	int hModel_;
	XMFLOAT3 move_;
public:
	Bullet(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	void SetMove(XMFLOAT3 _move) { move_=_move; }
};

