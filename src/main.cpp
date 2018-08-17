#include <cstdlib>
#include <iostream>
#include <uQueue.h>
#include <cstring>
#include <sstream>

# include "Binarizer.h"
# include "Buffer.h"
# include "Gray.h"

# include "Reader.h"

using namespace std;


int main (int argc, char **argv)
{
	printf("Inicio\n");
	// Buffers
	
	Buffer buffer(),GrayToBin(),BinToAnal(),AnalToWriter();

	// Creamos las etapas
	
	Reader reader(Buffer(&buffer));
	
	Gray gray(Buffer(&buffer), Buffer(&GrayToBin));
	
	Binarizer binz(Buffer(&GrayToBin), Buffer(&BinToAnal));
	
	Image image = Image(1);
	
	
	

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
	
	printf("Fin\n");


	return 1;
}
