/*
RSA ENCRYPTION PROGRAM
*/

#include "header.h"

//Verify Signature
void verifySign()
{
	string pk = readFile("pk.txt"); //Read public key file
	
	uint64_t e = stoull(pk.substr(0, pk.find("|"))); //Get e
	uint64_t n = stoull(pk.substr(pk.find("|")+1)); //Get n
	
	string signStr = readFile("sig.txt"); //Read signature
	uint64_t sign; //Stores signature as int
	
	try
	{
		 sign = stoull(signStr);
	}
	catch (exception& e)
	{	
		cout << "\nError. File \"sig.txt\" may be corrupted. Please try again." << endl;
		return;
	}
		
	string message; //Stores message to verify against
	cout << "\nEnter Message to verify against: ";
	cin >> message;
	
	uint64_t signDecr = modular_pow(sign, e, n);//Decrypted Signature
	
	cout << "\nSignature Decrypted: " << signDecr << endl;
	
	cout << "\nVerification Outcome: ";
	
	if (to_string(signDecr) != message) //Actual verification
		cout << "False" << endl;	
	 else
	 	cout << "True" << endl;	

	cout << "\nVerification Complete!" << endl;
}

