#pragma once
#include "Interface.h"
class Urinal :
    public Interface
{
public:
    Urinal(Vec2 pos, Vec2 scale);
    ~Urinal();

public:
    void Update() override;
    void FinalUpdate() override;

public:
    void OnMouseEnter() override;
    void OnMouse() override;
    void OnMouseExit() override;

private:
    bool isFocused;
};

