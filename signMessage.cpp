/*
RSA ENCRYPTION PROGRAM
*/

#include "header.h"

//Sign Message
void signMessage()
{
	string sk = readFile("sk.txt"); //Read from secret key file
	string pk = readFile("pk.txt"); //Read from public key file
	
	uint64_t d = stoull(sk.substr(0, sk.find("|"))); //Get d
	uint64_t n = stoull(pk.substr(pk.find("|")+1)); //Get n
	
	string input; //Store message to sign as string
	uint64_t message; //Store message to sign
	
	//cout << "\nEnter message to encrypt: ";
	//cin >> input;
	
	cout << "\nReading message from file \"mssg.txt\"" << endl;
	input = readFile("mssg.txt");
	
	//Input validation
	if (!isInteger(input))
	{
		cout << "\nMessage must be an Integer. Please try again." << endl;
		return;
	}
	
	message = stoull(input);
	
	if (message >= n)
	{
		cout << "\nMessage value must be smaller than N. Please try again." << endl;
		return;
	}
	
	uint64_t sign = modular_pow(message, d, n); //Peform signing
	
	writeFile(to_string(sign), "sig.txt"); //Write signature to file
	
	cout << "\nMessage Signed: " << sign << endl;
	
	cout << "\nMessage has been written to file \"sig.txt\"" << endl;
}
