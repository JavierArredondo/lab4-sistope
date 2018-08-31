#ifndef BINARIZE_H
#define BINARIZE_H

# include <iostream>
# include <fstream>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "../include/Buffer.h"

_Task Binarize
{
	private:
		Buffer &last;
		Buffer &next;
		int umbral;
	protected:
		void main();
	public:
		Binarize();
		Binarize(Buffer &last, Buffer &next, int umbral);
		void binFilter();
		~Binarize(){};
};

#endif