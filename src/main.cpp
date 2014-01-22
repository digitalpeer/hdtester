/*
   $Id: main.cpp,v 1.3 2004/09/18 03:31:28 dp Exp $

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

#include "hdtester.h"

#include <string>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
   HdTester test;

   string path = "hdtester.bin";

   if (argc > 1)
   {
      path = argv[1];
   }

   try
   {
      test.writeread(path);
   }
   catch (string& e)
   {
      cerr << e << endl;
   }
   catch (...)
   {
      cerr << "Unknown error";
   }

   return 0;
}

