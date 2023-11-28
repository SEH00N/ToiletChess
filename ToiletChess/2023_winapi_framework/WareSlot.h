#pragma once
#include "Interface.h"
class WareSlot :
    public Interface
{
public:
	WareSlot(Vec2 pos, Vec2 scale, wstring textureName);
	~WareSlot();
};

