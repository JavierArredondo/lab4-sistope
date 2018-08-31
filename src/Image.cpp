# include "Image.h"

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
			if(this->bpp == 32)
				fread(matrix[i][j], sizeof(unsigned char), 4, myFile);
			else
				fread(matrix[i][j], sizeof(unsigned char), 3, myFile);
		}
	}
	this->isNearlyBlack = -1;
	this->no = number;
	fclose(myFile);
}

void Image::getSize()
{
	printf("Ancho: %i\nLargo: %i\n", width, height);
}
