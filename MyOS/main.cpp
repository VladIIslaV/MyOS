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

int main(int argc, char **argv) 
{
	thread AddTaskThread(AddTask);
	Map map;
	map.InitializeLog("Great_Log.txt");
	/*Magick::InitializeMagick("C:\\Program Files\\ImageMagick-7.0.8-Q8");
	Map map;
	map.Resize(100, 100);
	map.RandomFill('A', 'Z');
	map.Show();
	map.Save("COOLIMG.jpeg");*/
	while (1)
	{

		TaskMgr::CheckQCondition();
		this_thread::sleep_for(100ms);
	}

	return 0;
}