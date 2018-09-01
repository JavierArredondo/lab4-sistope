#ifndef WRITER_H
#define WRITER_H

# include <iostream>
# include <fstream>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "../include/Buffer.h"

_Task Writer
{
	private:
		Buffer &buffer;
		int max;
	protected:
		void main();
	public:
		Writer();
		Writer(Buffer &buffer, int max);
		void write();
		~Writer(){};
};

#endif