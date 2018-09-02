# include "../include/Writer.h"
# define ALPHA 3
# define RED 2
# define GREEN 1
# define BLUE 0

Writer::Writer(Buffer &buffer, int max, int flag):buffer(buffer){
	printf("5) Escritor creado\n");
	this->max = max;
	this->flag = flag;
};

void Writer::main(){
	printf("5.1) Escribiendo imagenes\n");
	while(1)
		write();
};

void Writer::write()
{
	Image img = this->buffer.b_pop();
	char str[100];
	sprintf(str, "%d", img.no);
	if (this->flag == 1)
	{
		if(img.isNearlyBlack == 1)
			printf("|  imagen_%s   |         yes       |\n", str);
		else 
			printf("|  imagen_%s   |         no        |\n", str);
	}
	// Escritura de la imagen
	char* route;
	route = (char*)malloc(sizeof(char)*50);
	strcpy(route,"../imagesbin/imagenbin_");
	strcat(route, str);
    strcat(route, ".bmp");
	FILE* myFile =fopen(route, "wb");
	if(!myFile)
	{
		perror("Image can't be saved. File not found.");
		exit(0);
	}
	// Se escribe la cabecera de la imagen
	fseek(myFile,0, SEEK_SET);
	fwrite(&img.bm, sizeof(char), 2, myFile);
	fwrite(&img.size, 4, 1, myFile);
	fwrite(&img.reserved, 4, 1, myFile);
	fwrite(&img.offset, 4, 1, myFile);
	fwrite(&img.metadata, 4, 1, myFile);
	fwrite(&img.width, 4, 1, myFile);
	fwrite(&img.height, 4, 1, myFile);
	fwrite(&img.planes, 2, 1, myFile);
	fwrite(&img.bpp, 2, 1, myFile);
	fwrite(&img.compress, 4, 1, myFile);
	fwrite(&img.imgsize, 4, 1, myFile);
	fwrite(&img.bpmx, 4, 1, myFile);
	fwrite(&img.bpmy, 4, 1, myFile); 
	fwrite(&img.colors, 4, 1, myFile);
	fwrite(&img.imxtcolors, 4, 1, myFile);
	// Se escribe la imagen binarizada
	int i, j;
	for(i = 0; i < img.height; i++)
		for(j = 0; j < img.width; j++)
		{
			fwrite(&img.matrix[i][j][RED], 1, 1, myFile);
			fwrite(&img.matrix[i][j][GREEN], 1, 1, myFile);
			fwrite(&img.matrix[i][j][BLUE], 1, 1, myFile);
			if(img.bpp == 32)
 				fwrite(&img.matrix[i][j][ALPHA], 1, 1, myFile);
		}
	fclose(myFile);
	free(route);
	if(img.no == this->max)
		exit(0);
};