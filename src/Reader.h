#ifndef READER_H
#define READER_H

# include <iostream>
# include <fstream>
# include <string>
# include <stdio.h>
# include <stdlib.h>
using namespace std;

class Reader
{
	public:
		Reader();
		Reader(Buffer aux);
		void readImage(int img);

	private:
		Buffer buffer;
};

#endif