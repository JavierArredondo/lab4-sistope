# include <iostream>
# include <fstream>
# include <string>
# include <stdio.h>
# include <cstdint>
# include "Image.cpp"
# include "Buffer.cpp"
using namespace std;
# define ALPHA 3
# define RED 2
# define GREEN 1
# define BLUE 0

class Binarizer
{
	private:
		Buffer prevBuffer;
		Buffer nextBuffer;

	public:
		Binarizer(Buffer pb, Buffer nb);
		void convertToBin(int umbral);
};

Binarizer::Binarizer(Buffer pb, Buffer nb)
{
	prevBuffer = pb;
	nextBuffer = nb;
}

void Binarizer::convertToBin(int umbral)
{
	Image img = prevBuffer.b_pop();
	int i,j;
	for (i = 0; i < img.height; i++)
	{
		for (j = 0; j < img.width; j++)
		{
			if (img.matrix[i][j][RED] > umbral)
			{
				img.matrix[i][j][RED] = 255;
				img.matrix[i][j][BLUE] = 255;
				img.matrix[i][j][GREEN] = 255;
			}
			else
			{
				img.matrix[i][j][RED] = 0;
				img.matrix[i][j][BLUE] = 0;
				img.matrix[i][j][GREEN] = 0;
			}
		}
	}
	nextBuffer.b_push(img);
}