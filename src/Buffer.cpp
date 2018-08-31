#include "../include/Buffer.h"

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
	Image img = images.front(); 
	images.pop(); 
	return img;
};

void Buffer::b_push(Image image) 
{
	images.push(image);
};