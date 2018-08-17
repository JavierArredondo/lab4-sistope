#ifndef BINARIZER_H
#define BINARIZER_H

# include <iostream>
# include <fstream>
# include <string>
# include <stdio.h>
# include <cstdint>

# define ALPHA 3
# define RED 2
# define GREEN 1
# define BLUE 0

#include "Buffer.h"

using namespace std;

class Binarizer
{

	Buffer prevBuffer;
	Buffer nextBuffer;	
	
	public:
		Binarizer(Buffer pb , Buffer nb);
		void convertToBin(int umbral);

};

#endif