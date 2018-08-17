#ifndef GRAY_H
#define GRAY_H

# include <iostream>
# include <fstream>
# include <string>
# include <stdio.h>
# include <cstdint>

# define ALPHA 3
# define RED 2
# define GREEN 1
# define BLUE 0

using namespace std;

class Gray
{
	public:
		Gray();
		Gray(Buffer pb, Buffer nb);
		void convertToGray();
	
	private:
		Buffer prevBuffer;
		Buffer nextBuffer;
	
};

#endif