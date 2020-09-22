/*
RSA ENCRYPTION PROGRAM
*/

#include "header.h"

//Verify Signature
void encrypt()
{
	string pk = readFile("pk.txt"); //Read public key file
	
	uint64_t e = stoull(pk.substr(0, pk.find("|"))); //Get e
	uint64_t n = stoull(pk.substr(pk.find("|")+1)); //Get n
	
	string input;
	cout << "Enter plaintext: ";
	cin >> input;
	
	uint64_t plain;
	
	if (!isInteger(input))
	{
		cout << "Input must be an Integer" << endl;
		return;
	}
	
	plain = stoull(input);
	
	uint64_t cipher = modular_pow(plain, e, n);//Ciphertext
	
	cout << "\nEncryption complete!" << endl;
	
	cout << "\nCiphertext: " << cipher << endl;
}

