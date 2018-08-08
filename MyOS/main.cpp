#include <iostream>
#include <chrono>
#include <thread>
#include <stack>

#include "TaskMgr.h"
#include "CommandMgr.h"
#include "time.h"


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

int main() 
{
	
	thread AddTaskThread(AddTask);
	stack<char> st;
	
	while (1)
	{
		TaskMgr::CheckQCondition();
		this_thread::sleep_for(1s);
		//cout << endl << "### Round is finished" << endl;
		//taskMgr.checkCondition
	//	cout << CurrentTime();
	}

	return 0;
}