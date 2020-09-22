/*
RSA ENCRYPTION PROGRAM
*/

#include "header.h"

//Sign Message
void decrypt()
{
	string sk = readFile("sk.txt"); //Read from secret key file
	string pk = readFile("pk.txt"); //Read from public key file
	
	uint64_t d = stoull(sk.substr(0, sk.find("|"))); //Get d
	uint64_t n = stoull(pk.substr(pk.find("|")+1)); //Get n
	
	string input; //Store ciphertext to encrypt as string
	uint64_t cipher; //Store ciphertext to encrypt
	
	cout << "Enter ciphertext: ";
	cin >> input;
	
	//Input validation
	if (!isInteger(input))
	{
		cout << "Ciphertext must be an Integer. Please try again." << endl;
		return;
	}
	
	cipher = stoull(input);
	
	if (cipher >= n)
	{
		cout << "Ciphertext value must be smaller than N. Please try again." << endl;
		return;
	}
	
	uint64_t plain = modular_pow(cipher, d, n); //Peform decryption
	
	cout << "Decryption complete!" << endl;
	
	cout << "\nDecrypted text: " << plain << endl;
}
