// Timer.cpp	-thatcher 10/5/1999 by Thatcher Ulrich, donated to the public domain.

// Code for a millisecond timer.


#ifdef WIN32
#include <windows.h>
#include <mmsystem.h>
#else
#include <unistd.h>
#include <sys/timeb.h>
#endif

#include "timer.h"


namespace Timer {
;


#ifdef WIN32


unsigned StartTime = 0;


void	Open()
// Initialize timer module.  Get the current time and use it as the
// reference for later calls to GetTicks().
{
	StartTime = timeGetTime();
}


void	Close()
// Shut down the timer module.
{
}


int	GetTicks()
// Returns the number of ticks elapsed since Timer::Open() was called.
{
	unsigned	now = timeGetTime();
	return now - StartTime;
}


void	Sleep(int Milliseconds)
// Put this process to sleep for the specified number of milliseconds (approximately).
{
	::Sleep(Milliseconds);
}


#else	// LINUX


struct timeb	OpenTime;


void	Open()
// Initialize timer module.  Get the current time and use it as the
// reference for later calls to GetTicks().
{
	ftime(&OpenTime);
}


void	Close()
// Shut down the timer module.
{
}


int	GetTicks()
// Returns the number of ticks elapsed since Timer::Open() was called.
{
	struct timeb	now;

	ftime(&now);

	int	dsec;
	int	dms;

	dsec = now.time - OpenTime.time;
	dms = now.millitm - OpenTime.millitm;

	return dsec * 1000 + dms;
}


void	Sleep(int Milliseconds)
// Put this process to sleep for the specified number of milliseconds (approximately).
{
	usleep(Milliseconds * 1000);
}


#endif // not WIN32


};	// end namespace Timer


