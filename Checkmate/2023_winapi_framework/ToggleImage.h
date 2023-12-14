#pragma once
#include "Interface.h"

class Texture;

class ToggleImage : public Interface
{
public:
	ToggleImage(Vec2 pos, Vec2 scale, wstring tex1, wstring tex2);
	~ToggleImage();

public:
	void ToggleTexture();
	void SetTexture(int texID);
	Texture* GetTexture(int texID);

private:
	Texture* tex1;
	Texture* tex2;
};

