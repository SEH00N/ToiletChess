#pragma once
#include "Button.h"

class WareInventorySlot;

class WareImage :
    public Button
{
public:
    WareImage(Vec2 pos, Vec2 scale, wstring defaultTexName, wstring focusedTexName, int owner);
    ~WareImage();

public:
    void Update() override;

public:
    void SetStat(int confidence, int height) { this->confidence = confidence; this->height = height; }
    void SetSlot(WareInventorySlot* slot) { this->slot = slot; }
    int GetConfidence() { return confidence; }
    int GetHeight() { return height; }
    int GetOwner() { return owner; }
    WareInventorySlot* GetSlot() { return slot; }
    Texture* GetTexture() { return texture; }

public:
    Vec2 CalculateOffset(Vec2 mousePos);

private:
    void OnPressed(Vec2 pos);
    void OnClicked(Vec2 pos);

private:
    WareInventorySlot* slot;
    Vec2 offset;
    int confidence;
    int height;
    int owner;
};

