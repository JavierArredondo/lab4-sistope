# include "../include/Classifier.h"
# define ALPHA 3
# define RED 2
# define GREEN 1
# define BLUE 0

Classifier::Classifier(Buffer &last, Buffer &next, int umbral):last(last), next(next){
	this->umbral = umbral;
	printf("4) Clasificador creado\n");
};

void Classifier::main(){
	printf("4.1) Analizando\n");
	while(1)
		analize();
};

void Classifier::analize()
{
	Image img = this->last.b_pop();
	int black = 0;
	int i,j,percentage;
	for (i = 0; i < img.height; i++)
		for (j = 0; j < img.width; j++)
		{
			if (img.matrix[i][j][RED] == 255)
				black++;
		}
	percentage = (black * 100)/(img.height * img.width); 
	if(percentage >= this->umbral)
		img.isNearlyBlack = 1;
	else
		img.isNearlyBlack = 0;
	this->next.b_push(img);
};