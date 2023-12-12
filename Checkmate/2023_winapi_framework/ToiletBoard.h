#pragma once

class WareSlot;

class ToiletBoard
{
public:
	ToiletBoard();
	~ToiletBoard();

public:
	WareSlot* GetSlot(int line, int index);

private:
	// �Һ��� (0��) -> [][][][][][][][][][]
	// ��⿭ (1��) -> [][][][][][][][][][]
	std::vector<std::vector<WareSlot*>> slots;

private:
	const int BoardRow = 10;
};

