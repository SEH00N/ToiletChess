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
	// 소변기 (0번) -> [][][][][][][][][][]
	// 대기열 (1번) -> [][][][][][][][][][]
	std::vector<std::vector<WareSlot*>> slots;

public:
	// is return(slot, line, index)
	void ForeachSlot(std::function<bool(WareSlot*, int, int)> callback);

private:
	const int BoardRow = 10;
};

