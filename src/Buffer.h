#ifndef BUFFER_H
#define BUFFER_H

#include <uQueue.h>
# include <uC++.h>

#include "../Image.cpp"


_Monitor Buffer {	
	uQueue<Image> images;
	
	public:
		Buffer();
		//Image b_pop();
		//void b_push(Image image);
};


#endif