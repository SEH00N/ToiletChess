#pragma once

class WareBase;
class Urinal;

class GameMgr
{
	SINGLE(GameMgr)

public:
	WareBase* GetCurrentWare() const { return currentWare; }
	Urinal* GetCurrentUrinal() const { return currentUrinal; }
	void SetCurrentWare(WareBase* i) { currentWare = i; }
	void SetCurrentUrinal(Urinal* i) { currentUrinal = i; }

private:
	WareBase* currentWare;
	Urinal* currentUrinal;
};

