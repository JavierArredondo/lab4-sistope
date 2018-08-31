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
	protected:
		void main();
	public:
		Writer();
		Writer(Buffer &buffer);
		void write();
		~Writer(){};
};

#endif