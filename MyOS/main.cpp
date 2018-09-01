#include <iostream>
#include <chrono>
#include <thread>
#include <stack>
#include <Magick++.h>

#include "TaskMgr.h"
#include "CommandMgr.h"
#include "time.h"
#include "Map.h"


#define ENABLE 1
#define DISABLE 0
#define DEBUG ENABLE

using namespace std;
using namespace Magick;

void AddTask() 
{
	CommandMgr commander;
	string operation;
	int opcode;
	
	while (1)
	{
		operation = commander.GetCommand();
		opcode = CommandMgr::GetCommandOpCode(operation);
		CommandMgr::ExecuteCommand(opcode);
	}
}
#if 0
int main(int argc, char **argv) 
{
	thread AddTaskThread(AddTask);
	//Map map;
	//map.InitializeLog("Great_Log.txt");
	//Magick::InitializeMagick(*argv);
	Map map;
	map.Resize(100, 100);
	//map.RandomFill('A', 'Z');
	//map.Show();
	map.Save("COOLIMG.jpeg");
	while (1)
	{

		TaskMgr::CheckQCondition();
		this_thread::sleep_for(100ms);
	}

	return 0;
}
#endif
int main(int argc, char **argv)
{
    InitializeMagick(*argv);

    // Construct the image object. Seperating image construction from the 
    // the read operation ensures that a failure to read the image file 
    // doesn't render the image object useless. 
    char arr[10000];
    vector<short> vec(10000);
    try {
        for (int i = 0; i < 10000; i++)
        {
            Color c1(15000+i, 15000, 15000);
            Image image(Geometry(640, 480), Color(c1));
            image.write("img1.jpeg");
        }
        
    }
    catch (Exception &error_)
    {
        cout << "Caught exception: " << error_.what() << endl;
        system("pause");
        return 1;
    }
    system("pause");
    return 0;
}