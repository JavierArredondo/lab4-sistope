# include <iostream>
# include <fstream>
# include <string>
# include <stdio.h>
# include <stdlib.h>

class Image
{
	private:
		// Atributos
		char bm[2];      			// Bitmap
		int size;        			// Tamaño
		int reserved;    			// Reservado
		int offset;      			// 
		int metadata;    			// Tamaño de los metadados.
		int width;       			// Ancho
		int height;      			// Alto
		int planes;      			// Planos de color
		int bpp;         			// Bits por pixel
		int compress;    			// Compresión
		int imgsize;     			// Tamaño de los datos de la imagen
		int bpmx;        			// Resolución X en bits por metro 
		int bpmy;        			// Resolución Y en bits por metro
		int colors;      			// Colores usados en la paleta 
		int imxtcolors;  			// Colores importantes. 0 si son todos
		unsigned char ***matrix;	// 
	public:
		// Constructor
		Image(int number);
		// Metodos
		// Destructor
};

Image::Image(int number)
{
	char* image = (char*)calloc(60, sizeof(char));
	char* route = (char*)calloc(60, sizeof(char));
	sprintf(image, "%d", number);
	strcat(route, "./images/image_");
	strcat(route, image);
    strcat(route, ".bmp");
	FILE* myFile = fopen(route, "rb");
    if(myFile == NULL)
    {
		perror("File doesn't exist");
		exit(0);
    }
	// Lectura de header
	fseek(myFile, 0, SEEK_SET);
	fread(&bm, sizeof(char), 2, myFile);
	fread(&size, 4, 1, myFile);
	fread(&reserved, 4, 1, myFile);
	fread(&offset, 4, 1, myFile);
	fread(&metadata, 4, 1, myFile);
	fread(&width, 4, 1, myFile);
	fread(&height, 4, 1, myFile);
	fread(&planes, 2, 1, myFile);
	fread(&bpp, 2, 1, myFile);
	fread(&compress, 4, 1, myFile);
	fread(&imgsize, 4, 1, myFile);
	fread(&bpmx, 4, 1, myFile);
	fread(&bpmy, 4, 1, myFile); 
	fread(&colors, 4, 1, myFile);
	fread(&imxtcolors, 4, 1, myFile);
	// Lectura de pixeles
	matrix = (unsigned char***)malloc(sizeof(unsigned char**) * height);
	if(!matrix)
	{
		perror("Image can't be loaded. Matrix failed. Level 1");
		exit(0);
	}
	int i;
	for(i = 0; i < height; i++)
	{
		matrix[i] = (unsigned char**)malloc(sizeof(unsigned char*) * width);
		if(!matrix[i])
		{
			perror("Image can't be loaded. Matrix failed. Level 2");
			exit(0);
		}
		int j;
		for(j = 0; j < width; j++)
		{
			matrix[i][j] = (unsigned char*)malloc(sizeof(unsigned char) * 4);
			if(!matrix[i][j])
			{
				perror("Image can't be loaded. Matrix failed. Level 3");
				exit(0);
			}
			// B G R A
			// 0 1 2 3
			fread(matrix[i][j], sizeof(unsigned char), 4, myFile);
		}
	}
	fclose(myFile);
}