#pragma once
#include "Interface.h"
#include "TextBox.h"

class WareImage;

class WareInventorySlot :
    public Interface
{
public:
    WareInventorySlot(Vec2 pos, Vec2 scale, wstring texName);

public:
    void OnMouseEnter() override;
    void OnMouseExit() override;

public:
    void SetInfoText(wstring text) { textBox->SetText(text); }

public:
    void SetPos(Vec2 pos);
    void InitTextBox();

public:
    void SetWare(WareImage* ware) { this->ware = ware; }
    WareImage* GetWare() { return ware; }

private:
    WareImage* ware;
    TextBox* textBox;
};

