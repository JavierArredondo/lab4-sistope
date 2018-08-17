# include <iostream>
# include <fstream>
# include <string>
# include <stdio.h>
# include <stdlib.h>
using namespace std;


# include "main.cc"

class Reader
{
	private:
		miBuffer buffer;

	public:
		Reader(miBuffer b);
		void readImage(int img);
};
Reader::Reader(miBuffer b)
{
	buffer = b;
}

void Reader::readImage(int img)
{
	Image image(img);
	buffer.b_push(image);
}