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
	Image img(1);
	int qtyBuffer = 3; // Cantidad de B
	printf("Inicio\n");
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
	Writer writer(buffer4);

	delete &writer;
	delete &classifier;
	delete &binarize;
	delete &gray;
	delete &reader;



	// Se ejecutan las etapas.
}
