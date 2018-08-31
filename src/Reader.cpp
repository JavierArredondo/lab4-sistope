# include "../include/Reader.h"

Reader::Reader(Buffer &buffer, int qty):buffer(buffer){
	this->qty = qty;
	printf("1) Lector creado\n");
};

void Reader::readImage(int img){
	Image image(img);
	this->buffer.b_push(image);
};

void Reader::main(){
	int i;
	printf("1.1) Leyendo imagenes\n");
	for(i = 1; i <= this->qty; i++){
		readImage(i);
	}
};