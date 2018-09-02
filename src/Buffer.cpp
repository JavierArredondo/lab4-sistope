# include "../include/Buffer.h"
# include <uC++.h>

Buffer::Buffer(int size)
{
	this->size = size;
};

Buffer::Buffer()
{
	this->size = 0;
}

Image Buffer::b_pop() 
{
	if(this->images.empty())
	{
		this->full.wait();
	}
	Image img = images.front(); 
	images.pop();
	this->empty.signal();
	return img;
};

void Buffer::b_push(Image image) 
{
	if(this->images.size() == this->size)
	{
		//printf("Esta lleno\n");
		this->empty.wait();
	}
	images.push(image);
	this->full.signal();
};