#pragma once
#include "Object.h"

class Texture;

class BG : public Object
{
public:
	BG(wstring bgKey, wstring bgName);
	~BG();

public:
	void Update() override;
	void Render(HDC hDC) override;

private:
	Texture* texture;
};

