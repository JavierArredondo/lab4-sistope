#ifndef BUFFER_H
#define BUFFER_H

# include <uC++.h>
# include <queue>
# include "../include/Image.h"
using namespace std;

_Monitor Buffer{	
	private:
		int size;
		int empty;
		int full;
		queue<Image> images;
	
	public:
		Buffer();
		Buffer(int size);
		Image b_pop();
		void b_push(Image image);
		~Buffer(){};
};


#endif