#include "Map.h"



Map::Map()
{
	map = vector<vector<uint8_t>>();
	for (auto item : map)
	{
		item = vector<uint8_t>();
	}
}


/*
	X X X X X
	Y Y Y Y Y
	Y Y Y Y Y
	Y   Y Y
	Y     Y
	Y 
*/
void Map::Resize(int X, int Y)
{
	map.resize(X);
	for (auto &item : map)
	{
		item.resize(Y);
	}
}

void Map::Save(const char* fileName)
{
	uint8_t *arr = new uint8_t[10000];
	for (int i = 0; i < 10000; i++)
	{
		arr[i] = i % 255;
	}
	/*
	ofstream mapFile(fileName);
	Geometry imageGeom = Geometry(100, 100, 10, 20);
	Blob imageBlob = Blob(arr, 10000);
	Image newI = Image(imageBlob, imageGeom);
	newI.write(fileName);*/
	/*
	for (auto item : map)
	{
		for (auto brick : item)
		{
			mapFile << brick;
		}
		mapFile << endl;
	}*/
	//mapFile.close();
}

void Map::Show()
{
	for (auto item : map)
	{
		for (auto brick : item)
		{
			cout << (char)brick << " ";
		}
		cout << endl;
	}
}

uint8_t Map::GetBrick(int x, int y) const
{
	return map[y][x];
}

void Map::SetBrick(int x, int y, uint8_t brick)
{
	map[y][x] = brick;
}

void Map::RandomFill(uint8_t min, uint8_t max)
{
	for (auto &item : map)
	{
		for (auto &brick : item)
		{
			brick = rand()%(max-min) + min;
		}
	}
	cout << "Map filled by random values." << endl;
}



Map::~Map()
{
	for (auto &item : map)
	{
		item.clear();
	}
	map.clear();
}
