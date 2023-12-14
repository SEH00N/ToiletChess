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
    void SetRender(bool enable) { this->renderable = enable; }
    bool GetRender() { return renderable; }
    void SetFormat(unsigned int format) { this->format = format; }
    void SetTransparent(bool transparent) { this->transparent = transparent; }
    void SetFont(HFONT font) { this->font = font; }

private:
    wstring text;
    HFONT font;
    bool renderable;
    bool transparent;
    unsigned int format;
};

