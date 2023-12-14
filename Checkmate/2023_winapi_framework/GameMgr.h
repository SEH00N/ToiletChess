#pragma once

class WareImage;
class WareSlot;
class ToiletBoard;
class Inventory;
class TextBox;
class ToggleImage;

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
	void SetPlayerImage(ToggleImage* left, ToggleImage* right) {
		this->leftPlayerImage = left;
		this->rightPlayerImage = right;
	}

public:
	void ToggleInventory();
	void CalculatePlayerScore();
	bool CheckEnd();

private:
	int player1Score;
	int player2Score;

private:
	WareImage* currentWare;
	WareSlot* currentSlot;
	ToiletBoard* board;
	Inventory* inven1;
	Inventory* inven2;
	Inventory* currentInven;
	TextBox* noticeTextBox;
	ToggleImage* leftPlayerImage;
	ToggleImage* rightPlayerImage;
};

