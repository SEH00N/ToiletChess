#pragma once

class WareImage;
class WareSlot;

class GameMgr
{
	SINGLE(GameMgr)

public:
	WareImage* GetCurrentWare() const { return currentWare; }
	WareSlot* GetCurrentSlot() const { return currentSlot; }
	void SetCurrentWare(WareImage* i) { currentWare = i; }
	void SetCurrentSlot(WareSlot* i) { currentSlot = i; }

private:
	WareImage* currentWare;
	WareSlot* currentSlot;
};

