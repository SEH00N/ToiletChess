#pragma once

#include <functional>

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

public:
	// is return(slot, line, index)
	void ForeachSlot(std::function<bool(WareSlot*, int, int)> callback);

private:
	const int BoardRow = 10;
};

