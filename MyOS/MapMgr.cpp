#define _CRT_SECURE_NO_WARNINGS
#include "MapMgr.h"
#include <vector>


MapMgr::MapMgr()
{
}

void MapMgr::CreateMap()
{
	try 
	{
		vector<char> rgbt;
		for (int i = 10000; i; i--)
			rgbt.push_back(i);
		Blob blob(&rgbt[0], (rgbt.size() * sizeof(rgbt[0])));
		Image image;
		image.size("100x100");
		image.magick("RGB");
		image.read(blob);

	}
	catch (exception &error_)
	{
		cout << "Caught exception: " << error_.what() << endl;
		return;
	}
}


MapMgr::~MapMgr()
{
}
