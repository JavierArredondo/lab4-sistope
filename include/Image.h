#ifndef IMAGE_H
#define IMAGE_H

# include <iostream>
# include <fstream>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

class Image
{
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
		Image(int number);
		void getSize();
		~Image(){};
};

#endif