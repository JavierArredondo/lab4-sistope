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
	int quantityImages;
    int umbralImages;
    int umbralClassification;
    int flag = 0;
    int c;

    opterr = 0;


    printf("Cantidad de parametros: %d\n", argc);

    if (argc < 9)
    {
      printf("La cantidad de parametros en menor a la solicitada \n");
      abort ();
    }


    if (argc > 9)
    {
      printf("La cantidad de parametros en mayor a la solicitada \n");
      abort ();
    }

    while ((c = getopt (argc, argv, "c:u:n:b:")) != -1)
      switch (c)
        {
        case 'c':
          sscanf(optarg, "%d", &quantityImages);
          break;
        case 'u':
          sscanf(optarg, "%d", &umbralImages);
          break;
        case 'n':
          sscanf(optarg, "%d", &umbralClassification);
          break;
        case 'b':
          sscanf(optarg, "%d", &flag);
          break;
        case '?':
          if (optopt == 'c' || optopt == 'u' || optopt == 'n')
              fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
        default:
          abort ();
        }
    
    if ( quantityImages < 0  )
    {
      printf("Ingrese un numero positivo para la cantidad de imagenes que desea procesar\n");
    }

    if ( umbralImages <= 0 && umbralImages >= 255  )
    {
      printf("EL umbralImages (-u ) tiene que ser mayor a 0 y menor a 255\n");
      abort ();
    }

    if ( umbralClassification >= 100 && umbralClassification <= 0)
    {
      printf("La varible umbralClassification (-n ) tiene que ser mayor a 0 y menor a 100 \n");
      abort ();
    }

    //printf("%d\n", quantityImages);
    //printf("%d\n", umbralImages);
    //printf("%d\n", umbralClassification);
    //printf("%d\n", flag);


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
	Reader reader(buffer1, quantityImages);
	Gray gray(buffer1, buffer2);
	Binarize binarize(buffer2, buffer3, umbralImages);
	Classifier classifier(buffer3, buffer4, umbralClassification);
	Writer writer(buffer4, quantityImages,flag);
	
	delete &writer;
	delete &classifier;
	delete &binarize;
	delete &gray;
	delete &reader;
	delete &buffer4;
	delete &buffer3;
	delete &buffer2;
	delete &buffer1;

	// Se ejecutan las etapas.
}
