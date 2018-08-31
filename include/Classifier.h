#ifndef CLASSIFIER_H
#define CLASSIFIER_H

# include <iostream>
# include <fstream>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "../include/Buffer.h"

_Task Classifier
{
	private:
		Buffer &last;
		Buffer &next;
		int umbral;
	protected:
		void main();
	public:
		Classifier();
		Classifier(Buffer &last, Buffer &next, int umbral);
		void analize();
		~Classifier(){};
};

#endif