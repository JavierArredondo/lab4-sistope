# include "Image.h"
# include "Buffer.h"
# include "Reader.h"
using namespace std;

void uMain::main()
{
	printf("Inicio\n");
	// Buffers
	//Buffer ReadToBin(), GrayToBin(), BinToAnal(), AnalToWriter();
	Buffer buffer(1);
	Reader reader(buffer);
	// Creamos las etapas
	
	//Reader reader(Buffer(&ReadToBin));
	
	//Gray gray(Buffer(&buffer), Buffer(&GrayToBin));
	
	//Binarizer binz(Buffer(&GrayToBin), Buffer(&BinToAnal));
	

	//Image image(1);
	//image.getSize();
	
	
	

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
}
