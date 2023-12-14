#pragma once

class WareImage;
class WareSlot;
class ToiletBoard;
class Inventory;
class TextBox;

class GameMgr
{
	SINGLE(GameMgr)

public:
	WareImage* GetCurrentWare() const { return currentWare; }
	WareSlot* GetCurrentSlot() const { return currentSlot; }
	ToiletBoard* GetBoard() const { return board; }
	void SetInventory(Inventory* inven1, Inventory* inven2, Inventory* current) 
	{ this->inven1 = inven1; this->inven2 = inven2; this->currentInven = current; }
	void SetCurrentWare(WareImage* i) { currentWare = i; }
	void SetCurrentSlot(WareSlot* i) { currentSlot = i; }
	void SetBoard(ToiletBoard* i) { board = i; }
	void SetNoticeText(TextBox* textBox) { this->noticeTextBox = textBox; }

public:
	void ToggleInventory();
	bool CheckEnd();

private:
	WareImage* currentWare;
	WareSlot* currentSlot;
	ToiletBoard* board;
	Inventory* inven1;
	Inventory* inven2;
	Inventory* currentInven;
	TextBox* noticeTextBox;
};

