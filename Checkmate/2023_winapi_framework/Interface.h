#pragma once
#include "Object.h"

class Texture;

template <typename T>
class Action;

class Interface :
    public Object
{
public:
    Interface(Vec2 pos, Vec2 scale);
    ~Interface();

public:
    void Update() override;
    void Render(HDC hDC) override;

public:
    void SetTexture(wstring texName);
    void SetTexture(Texture* texture) { this->texture = texture; }
    void SetRender(bool enable) { this->renderable = enable; }
    bool GetRender() { return renderable; }

public:
    virtual void OnMouseEnter();
    virtual void OnMouse();
    virtual void OnMouseExit();

protected:
    bool renderable = false;
    bool onFocused = false;
    Texture* texture;
};

