#pragma once

class WareSlot;

class ToiletBoard
{
public:
	ToiletBoard();
	~ToiletBoard();

public:
	WareSlot* GetSlot(int line, int index) { return slots[line][index]; }

private:
	// 소변기 (0번) -> [][][][][][][][][][]
	// 대기열 (1번) -> [][][][][][][][][][]
	std::vector<std::vector<WareSlot*>> slots;
};

