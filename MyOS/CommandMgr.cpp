#include "CommandMgr.h"



CommandMgr::CommandMgr()
{
}


CommandMgr::~CommandMgr()
{
}

string CommandMgr::GetCommand()
{
	cout << ">>> ";

	// String to get command from the outside
	string userCmd;
	cin >> userCmd;

	// String for result command
	string resultCmd;

	// Number of commands that similar to user's command
	int numOfEqCommands = 0;

	// Transform user userCmd to lower case
	transform(userCmd.begin(), userCmd.end(), userCmd.begin(), ::tolower);
	for (string cmdFromList : commandList)
	{
		string lowCmdFromList(cmdFromList);
		// Transform commands from list to the lower case
		transform(cmdFromList.cbegin(), cmdFromList.cend(), lowCmdFromList.begin(), ::tolower);
		lowCmdFromList.resize(userCmd.size());

		if (userCmd.compare(lowCmdFromList) == 0)
		{
			cout << cmdFromList << endl;
			resultCmd = cmdFromList;
			numOfEqCommands++;
		}
	}
	if (numOfEqCommands != 1)
		resultCmd = string();
	else
		cout << ">>> " << resultCmd << endl;
	return resultCmd;
}

int CommandMgr::GetCommandOpCode(string operation)
{
	int result = 0;
	if (operation == string())
	{
		result = -1;
	}
	for (int i = 0; i < commandList.size(); i++)
	{
		if (operation == commandList[i])
			result = i;
	}
	return result;
}

void CommandMgr::ExecuteCommand(int opcode)
{
	TaskEntry newTask;
	switch(opcode)
	{
	case 0:	//Add empty task
		TaskMgr::CreateTask(newTask);
		break;
	case 1:	//Add task
		cin >> &newTask;
		TaskMgr::CreateTask(newTask);
		break;
	case 2:	//Delete task
		// TODO: define function
		cout << "\nDeleteTask function hasn't defined yet" << endl;
		break;
	case 3:	//Free task pool
		TaskMgr::FreeTaskPool();
		break;
	case 4:	//Show task list
		TaskMgr::ShowTaskList();
		break;
	case 5:	//Finish execution
		exit(0);
		break;
	case 6:	//Help
		CommandMgr::ShowCmdList();
		break;

	default:
		cout << endl << "Warning: Command doesn't recognized" << endl;
	}
}

void CommandMgr::ShowCmdList()
{
	cout  << endl << "\tCOMMAND LIST:" << endl;
	for (string command : commandList)
	{
		cout << command << endl;
	}
}
