#pragma once
#include "Interface.h"

class Texture;

class Button :
    public Interface
{
public:
	Button(Vec2 pos, Vec2 scale, wstring buttonName, wstring defaultTexName, wstring eventTexName);
	~Button();

public:
	void Update() override;

public:
	void OnMouseEnter() override;
	void OnMouse() override;
	void OnMouseExit() override;

public:
	void (*OnButtonPressed)();

private:
	Texture* defaultTex;
	Texture* eventTex;
};

