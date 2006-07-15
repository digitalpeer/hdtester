/*
   $Id: hdtester.h,v 1.2 2004/08/21 05:08:33 dp Exp $
                                                                                                                             
   hdtester
                                                                                                                             
   Copyright (C) 2004, J.D. Henderson <www.digitalpeer.com>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/** @file
@brief Hard Drive Tester Class. */
#ifndef HDTESTER_H
#define HDTESTER_H

#include "timer.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** @class HdTester
@brief write a binary file and time it */
class HdTester
{
	public:
		/** Number of ints to write */
		static const unsigned int BUFFER_SIZE;
		static const unsigned int BUFFER_TIMES;

	  	HdTester();

		/** Write a new file */
		bool write(string path);

		/** Read a file that exists */
		bool read(string path);

		/** Write a file then read it right back in */
		bool writeread(string path);

	private:

		/** Close the archive */
		void close();

	  	/** Open the archive */
		void open(string path, bool write = true);

		inline void writeBin(const char* buffer, size_t size);

		inline void readBin(char* buffer, size_t size);

		/** The file we are rw to */
		fstream out;
};

#endif
