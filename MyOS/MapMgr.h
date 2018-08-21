#pragma once

#include <fstream>
#include <vector>

#include "Map.h"

#include <Magick++.h>

using namespace Magick;

using namespace std;


class MapMgr
{
	vector<string> mapList;
	Map map;
public:
	MapMgr();

	static void CreateMap();	// maybe will be better to remove static statement
	void ReadMap(int mapId);
	void SaveMapToFile();

	~MapMgr();
private:
	int CreateMapList();	// create list of existed maps
};

