/*
RSA ENCRYPTION PROGRAM
*/

#include "header.h"

//Generate keys
void keyGen()
{
	int bitSize; //Stores size of bits for p and q
	string input; //Stores input from user as string
	
	cout << "\nEnter bit size of p and q: ";
	cin >> input;
	
	//Input Validation
	if (!isInteger(input))
	{
		cout << "\nInput must be an Integer. Please try again." << endl;
		return;
	}	
	try
	{
		bitSize = stoi(input);
	}
	catch (exception& e)
	{
		cout << "\nInput processing error" << endl;
		return;
	}
	
	if (bitSize > 32)
	{
		cout << "\nBit size cannot exceed 32 bits. Please try again" << endl;
		return;
	}
	
	//Generating p and q
	
	srand (time(NULL)); //Rand seed
	
	uint64_t p; //Store p
	uint64_t q; //Store q
	
	bool found = false; //Flag for if valid p and q are found
	
	//Generate p and q
	do
	{
		p = rand() % (uint64_t)pow(2, bitSize) + 1; //Random number
		q = rand() % (uint64_t)pow(2, bitSize) + 1; //Random number
		
		if (isPrime(q) && isPrime(p) && p != q) //Check for prime and inequality
			found = true;
			
	}while(found == false);
	
	//Generating n and m
	uint64_t n = p * q;
	uint64_t m = (p-1) * (q-1);
	
	//Generating e and d
	uint64_t e;
	
	do
	{
		e = rand () % (m-1) + 1; //Random value
	
	}while(gcd(e, m) != 1); //e must be coprime with m
	
	//Generating d
	uint64_t d = aInverseModb(e, m); //Inverse of e modulo m
	
	//Generate keys
	string pk = to_string(e) + "|" + to_string(n); //Public Key
	string sk = to_string(d) + "|" + to_string(p) + "|" + to_string(q); //Secret Key
	
	//Write keys to corresponding files
	writeFile(pk, "pk.txt"); 
	writeFile(sk, "sk.txt");
	
	cout << "\nKey Generation Complete!" << endl;
	cout << "\nKeys written to files \"pk.txt\" and \"sk.txt\"" << endl;
}

