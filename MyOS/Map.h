#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <Magick++.h>
#include <Magick++/Image.h>

using namespace std;

class Map
{
	vector<vector<uint8_t>> map;
public:
	Map();

	void Resize(int X, int Y);
	void Save(const char* fileName);
	void Read();
	void Show();
	uint8_t GetBrick(int x, int y) const;
	void SetBrick(int x, int y, uint8_t brick);
	void RandomFill(uint8_t min, uint8_t max);

	~Map();
};

