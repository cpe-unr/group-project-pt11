test: main.cpp wav.o menus.o
	g++ -std=c++11 -o test main.cpp wav.o menus.o

menus.o: menus.cpp menus.h
	g++ -std=c++11 -c menus.cpp

wav.o: wav.cpp wav.h waveheader.h
	g++ -std=c++11 -c wav.cpp

clean:
	rm test *.o