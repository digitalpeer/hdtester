#  $Id: Makefile,v 1.2 2004/08/21 05:08:31 dp Exp $
#
#  hdtester
#
#  Copyright (C) 2004, J.D. Henderson <www.digitalpeer.com>
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

# source files.
SRC = 	src/main.cpp src/hdtester.cpp src/timer.cpp

OBJ = $(SRC:.cpp=.o)

OUT = hdtester

# C++ compiler flags (-g -O2 -Wall)
CCFLAGS = -g

# compilers to use
CCC = g++

# library paths
LDFLAGS=-g

.SUFFIXES: .cpp

.cpp.o:
	$(CCC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	$(CCC) $(LDFLAGS) -o $(OUT) $(OBJ)

clean:
	rm -f $(OBJ) Makefile.bak $(OUT)


