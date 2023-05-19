a.out : 1_client.o 1_complex.o
	g++ 1_client.o 1_complex.o
1_client.o : 1_client.cpp 1_complex.h
	g++ -c 1_client.cpp
1_complex.o : 1_complex.cpp 1_complex.h
	g++ -c 1_complex.cpp
	
