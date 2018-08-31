#ifndef BUFFER_H
#define BUFFER_H

# include <queue>
# include "../include/Image.h"
using namespace std;

_Monitor Buffer{	
	private:
		uCondition full, empty;
		int size;
		queue<Image> images;
	
	public:
		Buffer();
		Buffer(int size);
		Image b_pop();
		void b_push(Image image);
		~Buffer(){};
};


#endif