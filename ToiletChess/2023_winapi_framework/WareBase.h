#pragma once
#include "Button.h"

class WareBase : public Button
{
public:
	WareBase(Vec2 pos, Vec2 scale, wstring buttonName, wstring defaultTexName, wstring eventTexName);
	~WareBase();

public:
	void Update() override;

public:
	void OnClicked();

public:
	void SetConfidence(int i) { confidence = i; }
	void SetHeight(int i) { height = i; }

public:
	bool CheckFront(WareBase& right);
	bool CheckSide(WareBase& right);

private:
	Vec2 offset;
	int confidence;
	int height;
};

