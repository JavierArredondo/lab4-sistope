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

class Gray
{
	private:
		Buffer prevBuffer;
		Buffer nextBuffer;

	public:
		Gray(Buffer pb, Buffer nb);
		void convertToGray();
};

Gray::Gray(Buffer pb, Buffer nb)
{
	prevBuffer = pb;
	nextBuffer = nb;
}

void Gray::convertToGray()
{
	Image img = prevBuffer.b_pop();
	int tmp, i, j;
	for (i = 0; i < img.height; i++)
		for (j = 0; j < img.width; j++)
		{
			// Y = R ∗ 0.3 + G ∗ 0.59 + B ∗ 0.11
			tmp = img.matrix[i][j][RED]* 0.3 + img.matrix[i][j][GREEN] * 0.59 + img.matrix[i][j][BLUE] * 0.11;
			img.matrix[i][j][RED] = tmp;
			img.matrix[i][j][GREEN] = tmp;
			img.matrix[i][j][BLUE] = tmp;
		}
	nextBuffer.b_push(img);
}