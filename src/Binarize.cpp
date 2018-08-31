# include "../include/Binarize.h"
# define ALPHA 3
# define RED 2
# define GREEN 1
# define BLUE 0

Binarize::Binarize(Buffer &last, Buffer &next, int umbral):last(last), next(next){
	printf("3) Binarizador creado\n");
	this->umbral = umbral;
};

void Binarize::main(){
	printf("3.1) Aplicando filtro\n");
	while(1)
		binFilter();
};

void Binarize::binFilter(){
	Image img = last.b_pop();
	int i,j;
	for (i = 0; i < img.height; i++)
	{
		for (j = 0; j < img.width; j++)
		{
			if (img.matrix[i][j][RED] > this->umbral)
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
	next.b_push(img);
};