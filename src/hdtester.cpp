/*
 * hdtester
 *
 * Copyright (C) 2004, J.D. Henderson <www.digitalpeer.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "hdtester.h"

const unsigned int HdTester::BUFFER_SIZE = 10000;
const unsigned int HdTester::BUFFER_TIMES = 10000;

HdTester::HdTester()
{
   close();
}

void HdTester::open(string path, bool write)
{
   close();

   if (write)
      out.open(path.c_str(),ios::out | ios::binary | ios::trunc);
   else
      out.open(path.c_str(),ios::in | ios::binary | ios::ate);

   if (!out.good())
   {
      throw string("Could not open file " + path);
   }
}

bool HdTester::writeread(string path)
{
   Timer::Open();

   open(path,true);

   write(path);

   open(path,false);

   read(path);

   if (unlink(path.c_str()) == -1)
      return false;
   else
      return true;

   return true;
}

bool HdTester::write(string path)
{
   char value[BUFFER_SIZE];

   cout << "Writing file size( "  << BUFFER_SIZE*BUFFER_TIMES << "b ) ... " << flush;

   long start = Timer::GetTicks();

   for (unsigned int x = 0; x < BUFFER_TIMES; x++)
   {
      writeBin(value,sizeof(value));
   }

   long end = Timer::GetTicks();

   Timer::Close();

   cout << "Done in " << end-start << "ms."<< endl;

   return true;
}

bool HdTester::read(string path)
{
   char value[BUFFER_SIZE];

   int size = out.tellg();

   out.seekg(ios::beg);

   cout << "Reading file size( "  << size << "b ) ... " << flush;

   long start = Timer::GetTicks();

   for (unsigned int x = 0; x < BUFFER_TIMES; x++)
   {
      readBin(value,sizeof(value));
   }

   long end = Timer::GetTicks();

   Timer::Close();

   cout << "Done in " << end-start << "ms."<< endl;

   return true;
}

inline void HdTester::writeBin(const char* buffer, size_t size)
{
   if (out.fail())
   {
      throw string("In failed state when trying to write.");
   }

   out.write(buffer,size);
}

inline void HdTester::readBin(char* buffer, size_t size)
{
   if (out.eof())
   {
      throw string("End of file encountered when expecting more data.");
   }

   if (out.fail())
   {
      throw string("In failed state when trying to read.");
   }

   out.read(buffer,size);
}

void HdTester::close()
{
   if (out.is_open())
      out.close();
}
