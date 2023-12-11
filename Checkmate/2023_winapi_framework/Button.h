#pragma once
#include <functional>
#include "Interface.h"
#include "Action.h"

class Button :
    public Interface
{
public:
    Button(Vec2 pos, Vec2 scale, wstring defaultTexName, wstring focusedTexName);
    ~Button();

public:
    void Update() override;

public:
    void OnMouseEnter() override;
    void OnMouseExit() override;

public:
    void RegisterPressed(std::function<void()> callback) { OnPressedEvent = callback; }
    void RegisterClicked(std::function<void()> callback) { OnClickedEvent = callback; }

protected:
    std::function<void()> OnPressedEvent;
    std::function<void()> OnClickedEvent;
    Texture* defaultTex;
    Texture* focusedTex;
    bool pressed;
};

