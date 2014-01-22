// Timer.hpp    -thatcher 10/5/1999 by Thatcher Ulrich, donated to the public domain.

// Timer functions.


#ifndef TIMER_HPP
#define TIMER_HPP

namespace Timer
{
void    Open();
void    Close();

int GetTicks(); // Return milliseconds elapsed since Open().

void    Sleep(int Milliseconds);
};



#endif // TIMER_HPP

