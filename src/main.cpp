# include <uC++.h>
# include "Image.h"
# include "Buffer.h"
# include "Reader.h"
# include "Gray.h"
# include "Binarize.h"
# include "Classifier.h"
# include "Writer.h"

using namespace std;

void uMain::main()
{
	// getOpt->[argv]
	int qtyBuffer = 3; // Cantidad de B
	printf("Inicio\n");
	// int b = getOpt.getBuffers();
	// int n = getOpt.getImages();
	// Buffers: Buffers en comun entre cada etapa 
	Buffer buffer1(qtyBuffer);
	Buffer buffer2(qtyBuffer);
	Buffer buffer3(qtyBuffer);
	Buffer buffer4(qtyBuffer);
	// Creamos las etapas
	Reader reader(buffer1, 20);
	Gray gray(buffer1, buffer2);
	Binarize binarize(buffer2, buffer3, 50);
	Classifier classifier(buffer3, buffer4, 50);
	Writer writer(buffer4, 20);

	delete &writer;
	delete &classifier;
	delete &binarize;
	delete &gray;
	delete &reader;
	delete &buffer4;
	delete &buffer3;
	delete &buffer2;
	delete &buffer1;
	printf("Fin\n");
	// Se ejecutan las etapas.
}
