#ifndef BUFFER_H
#define BUFFER_H

# include <queue>
# include <uC++.h>

#include "Image.h"


_Monitor Buffer {
	
	queue<Image> images;
	
	public:
		Buffer() : images(null) {}
		Image b_pop() {}
		void b_push(Image image) {}

};

#endif