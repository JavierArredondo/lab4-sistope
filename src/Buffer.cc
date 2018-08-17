#include "Buffer.h"

Buffer::Buffer(){
}

Image Buffer::b_pop() 
{
	Image img = images.front(); 
	images.pop(); 
	return img;
}

void Buffer::b_push(Image image) 
{
	images.push(image);
}
