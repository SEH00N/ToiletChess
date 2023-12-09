#pragma once
#include "Button.h"

class WareInventorySlot;

class WareImage :
    public Button
{
public:
    WareImage(Vec2 pos, Vec2 scale, wstring defaultTexName, wstring focusedTexName);
    ~WareImage();

public:
    void Update() override;

public:
    void SetSlot(WareInventorySlot* slot) { this->slot = slot; }
    WareInventorySlot* GetSlot() { return slot; }

public:
    Vec2 CalculateOffset(Vec2 mousePos);

private:
    void OnPressed(Vec2 pos);
    void OnClicked(Vec2 pos);

private:
    WareInventorySlot* slot;
    Vec2 offset;
};

