#include "Reader.h"

Reader::Reader(Buffer aux)
{
	buffer = aux;
}

void Reader::readImage(int img)
{
	Image image(img);
	buffer.b_push(image);
}