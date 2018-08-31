#ifndef GRAY_H
#define GRAY_H

# include <iostream>
# include <fstream>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "../include/Buffer.h"

_Task Gray
{
	private:
		Buffer &last;
		Buffer &next;
	protected:
		void main();
	public:
		Gray();
		Gray(Buffer &last, Buffer &next);
		void grayFilter();
		~Gray(){};
};

#endif