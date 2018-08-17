#include <cstdlib>
#include <iostream>
#include <queue>
#include <cstring>
#include <sstream>

#include "Binarizer.h"
#include "Buffer.h"
#include "Gray.h"
#include "Image.h"
#include "Reader.h"

using namespace std;


void uMain:main (int argc, char **argv)
{
	printf("Inicio\n");
	// Buffers
	//Buffer ReadToGray(), GrayToBin(), BinToAnal(), AnalToWriter();
	Buffer ReadToGray = Buffer();
	// Creamos las etapas
	
	Reader reader = Reader(ReadToGray);
	//reader.printt();
	//Gray gray(ReadToGray, GrayToBin);
	//Binarizer binz(GrayToBin, BinToAnal);
	
	Image image(1);
	
	//reader.read(1);
	//gray.convertToGray();
	

	// getopt
	// ....Lee imagen
	// buffer-> encola
	// buffer-> desencola
	// .....Convierte imagen a gris
	// buffer-> encola
	// buffer-> desencola
	// .....Binariza imagen
	// buffer-> encola
	// buffer-> desencola
	// .....categoriza
	// buffer-> encola
	// buffer-> desencola
	// ......escribe

	delete ReadToGray;
	delete reader;
	delete Image;
	
	printf("Fin\n");
}
