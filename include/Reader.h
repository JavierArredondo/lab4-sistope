#ifndef READER_H
#define READER_H

# include <iostream>
# include <fstream>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "../include/Buffer.h"

_Task Reader
{
	private:
		Buffer &buffer;
		int qty;
	protected:
		void main();
	public:
		Reader();
		Reader(Buffer &buffer, int qty);
		void readImage(int img);
		~Reader(){};
};

#endif