#RSA ENCRYPTION PROGRAM

RSA.out: main.o header.h keyGen.o signMessage.o verifySign.o utilities.o encryption.o decryption.o
	g++ -o RSA.out main.o header.h keyGen.o signMessage.o verifySign.o utilities.o encryption.o decryption.o

main.o: main.o header.h keyGen.o signMessage.o verifySign.o utilities.o
	g++ -c main.cpp

keyGen.o: keyGen.cpp header.h 
	g++ -c keyGen.cpp

signMessage.o: signMessage.cpp header.h 
	g++ -c signMessage.cpp

verifySign.o: verifySign.cpp header.h 
	g++ -c verifySign.cpp

utilities.o: utilities.cpp header.h 
	g++ -c utilities.cpp

encryption.o: encryption.cpp header.h 
	g++ -c encryption.cpp
	
decryption.o: decryption.cpp header.h 
	g++ -c decryption.cpp

clean:
	rm *.o RSA.out
