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
    void RegisterClicked(std::function<void(Vec2)> callback) { OnClickedEvent.RegisterEvent(callback); }

private:
    Action<Vec2> OnClickedEvent;
    Texture* defaultTex;
    Texture* focusedTex;
    bool pressed;
};

