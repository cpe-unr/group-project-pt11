test: main.cpp wav.o
	g++ -std=c++11 -o test main.cpp wav.o

wav.o: wav.cpp wav.h waveheader.h
	g++ -std=c++11 -c wav.cpp

clean:
	rm test *.o