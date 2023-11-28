#pragma once
#include "Interface.h"
#include <functional>

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
	void RegisterReleased(std::function<void()> callback) { onButtonReleased = callback; }
	void RegisterClicked(std::function<void()> callback) { onButtonClicked = callback; }

private:
	std::function<void()> onButtonClicked;
	std::function<void()> onButtonReleased;

private:
	Texture* defaultTex;
	Texture* eventTex;

protected:
	bool clicked;
};

