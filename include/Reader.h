#ifndef READER_H
#define READER_H

# include <iostream>
# include <fstream>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "../include/Buffer.h"
# include <uC++.h>

class Reader
{
	private:
		Buffer &buffer;
	public:
		Reader();
		Reader(Buffer &buffer);
		~Reader(){};
};

#endif