finalProgram: main.cpp wav.o menus.o wavProcessing.a
	g++ -std=c++11 -o finalProgram main.cpp wav.o menus.o wavProcessing.a

menus.o: menus.cpp menus.h
	g++ -std=c++11 -c menus.cpp

wav.o: wav.cpp wav.h waveheader.h saveFile.h
	g++ -std=c++11 -c wav.cpp

echo.o: echo.cpp echo.h
	g++ -std=c++11 -c echo.cpp

normalization.o: normalization.cpp normalization.h
	g++ -std=c++11 -c normalization.cpp

noiseGate.o: noiseGate.cpp noiseGate.h
	g++ -std=c++11 -c noiseGate.cpp

processor.o: processor.cpp processor.h
	g++ -std=c++11 -c processor.cpp

wavProcessing.a: echo.o normalization.o noiseGate.o processor.o
	ar suvr wavProcessing.a echo.o normalization.o noiseGate.o processor.o

clean:
	rm finalProgram *.o *.a