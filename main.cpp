#include <cstdlib>
#include <iostream>
//#include <queue>
# include "Image.cpp"
# include "Buffer.cpp"
//# include "Reader.cpp"
using namespace std;
//# include "Binarizer.cpp"

int main(int argc, char **argv)
{
	printf("Inicio\n");
	// Buffers
	Buffer ReadToGray(), GrayToBin(), BinToAnal(), AnalToWriter();
	// Creamos las etapas
	//Reader reader();
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
	printf("Fin\n");
	return 0;
}
