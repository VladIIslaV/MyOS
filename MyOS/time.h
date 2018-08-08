#pragma once

#include <time.h>

// Time from the start of the programm execution
static time_t CurrentTime() 
{
	time_t curTime = 0;
	static time_t startTime = time(&curTime);

	return time(&curTime) - startTime;
}