# include "../include/Gray.h"
# define ALPHA 3
# define RED 2
# define GREEN 1
# define BLUE 0

Gray::Gray(Buffer &last, Buffer &next):last(last), next(next){
	printf("2) Gray creado\n");
};

void Gray::main(){
	printf("2.1) Aplicando filtro\n");
	while(1){
		grayFilter();
	}
};

void Gray::grayFilter(){
	Image img = this->last.b_pop();
	int tmp, i, j;
	for (i = 0; i < img.height; i++)
		for (j = 0; j < img.width; j++)
		{
			// B G R A
			// 0 1 2 3
			// Y = R ∗ 0.3 + G ∗ 0.59 + B ∗ 0.11
			tmp = img.matrix[i][j][RED]* 0.3 + img.matrix[i][j][GREEN] * 0.59 + img.matrix[i][j][BLUE] * 0.11;
			img.matrix[i][j][RED] = tmp;
			img.matrix[i][j][GREEN] = tmp;
			img.matrix[i][j][BLUE] = tmp;
		}
	this->next.b_push(img);
};