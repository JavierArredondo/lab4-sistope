#ifndef READER_H
#define READER_H

# include <iostream>
# include <fstream>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "../include/Buffer.h"
# include <uC++.h>

_Task Reader
{
	private:
		Buffer &buffer;
	public:
		Reader(Buffer &buffer);
		~Reader(){};
};

#endif