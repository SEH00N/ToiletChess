#pragma once
#include "Object.h"
class TextBox :
    public Object
{
public:
    TextBox(Vec2 pos, Vec2 scale, wstring text);
    ~TextBox();

public:
    void Render(HDC hDC) override;

public:
    void SetText(wstring text) { this->text = text; }
    wstring GetText() { return text; }

private:
    wstring text;
};

