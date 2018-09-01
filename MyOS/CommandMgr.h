#pragma once

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "TaskMgr.h"

using namespace std;

/*
There described interface Man-OS. It will bw used throught serial connection.

TODO:	Should be described command manager for work inside OS. 
		Command of this type will be user with tasks.
*/

static const vector<string> commandList =
{// OPERATION				OPCODE
	"AddEmptyTask",			// 0
	"AddTask",				// 1
	"DeleteTask",			// 2
	"FreeTaskPool",			// 3
	"ShowTaskList",			// 4
	"Exit",					// 5
	"Help",					// 6
	"AddGetPositionTask",	// 7
	"Time",					// 8
	"GlobalTime"			// 9 TODO: define command
};

class CommandMgr
{

public:
	CommandMgr();
	~CommandMgr();

	// Return opcode
	static string GetCommand();
	static int GetCommandOpCode(string operation);
	static void ExecuteCommand(int opcode);
	static void ShowCmdList();
};

