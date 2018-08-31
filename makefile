INC_DIRS = -Iinclude

CFLAGS = -c

main: obj/main.o obj/Buffer.o obj/Image.o obj/Reader.o obj/Gray.o obj/Binarize.o obj/Classifier.o obj/Writer.o
	@ u++ obj/*.o -o bin/classifier.out
	@ echo "The compilation has been completed successfully!"

obj/main.o: src/main.cpp
	@ echo "src/main.cpp"
	@ u++  $(CFLAGS) $(INC_DIRS) src/main.cpp -o obj/main.o
obj/Buffer.o: src/Buffer.cpp
	@ echo "src/Buffer.cpp"
	@ u++  $(CFLAGS) $(INC_DIRS) src/Buffer.cpp -o obj/Buffer.o
obj/Image.o: src/Image.cpp
	@ echo "src/Image.cpp"
	@ u++  $(CFLAGS) $(INC_DIRS) src/Image.cpp -o obj/Image.o
obj/Reader.o: src/Reader.cpp
	@ echo "src/Reader.cpp"
	@ u++  $(CFLAGS) $(INC_DIRS) src/Reader.cpp -o obj/Reader.o
obj/Gray.o: src/Gray.cpp
	@ echo "src/Gray.cpp"
	@ u++  $(CFLAGS) $(INC_DIRS) src/Gray.cpp -o obj/Gray.o
obj/Binarize.o: src/Binarize.cpp
	@ echo "src/Binarize.cpp"
	@ u++  $(CFLAGS) $(INC_DIRS) src/Binarize.cpp -o obj/Binarize.o
obj/Classifier.o: src/Classifier.cpp
	@ echo "src/Classifier.cpp"
	@ u++  $(CFLAGS) $(INC_DIRS) src/Classifier.cpp -o obj/Classifier.o
obj/Writer.o: src/Writer.cpp
	@ echo "src/Writer.cpp"
	@ u++  $(CFLAGS) $(INC_DIRS) src/Writer.cpp -o obj/Writer.o

clean:
	@ clear
	@ echo "Cleaning folders.."
	@ rm -rf obj/*
	@ rm -rf bin/*
	@ rm -rf images/*