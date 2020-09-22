/*
RSA ENCRYPTION PROGRAM
*/

#include "header.h"

int main()
{
	cout << "Welcome to RSA program" << endl;
	cout << "---------------------------------------------\n" << endl;
	
	char choice; //Menu choice
	
	//Menu
	do
	{
		cout << "Select Operation:\n\t1. Generate Key\n\t2. Sign Message\n\t3. Verify Signature";
		cout << "\n\t4. Encrypt\n\t5. Decrypt\n\t6. Exit" << endl;
		cout << "\nYour choice: ";
		cin >> choice;	
		
		cin.clear();
		cin.ignore(10000, '\n');
		
		switch(choice)
		{
			case '1':{	//Key Generation
					cout << "\n---------------------------------------------\n" << endl;
					cout << "Key Generation" << endl;
					keyGen();
					cout << "\n---------------------------------------------\n" << endl;	
				}
				break;
			case '2':{	//Message Signing
					cout << "\n---------------------------------------------\n" << endl;
					cout << "Message Signing" << endl;
					signMessage();
					cout << "\n---------------------------------------------\n" << endl;	
				}
				break;
			case '3':{	//Singature verification
					cout << "\n---------------------------------------------\n" << endl;
					cout << "Signature Verification" << endl;
					verifySign();
					cout << "\n---------------------------------------------\n" << endl;	
				}
				break;
			case '4':{	//Encryption
					cout << "\n---------------------------------------------\n" << endl;
					cout << "Encryption" << endl;
					encrypt();
					cout << "\n---------------------------------------------\n" << endl;	
					
				}
				break;
			case '5':{	//Decryption
					cout << "\n---------------------------------------------\n" << endl;
					cout << "Decryption" << endl;
					decrypt();
					cout << "\n---------------------------------------------\n" << endl;	
				}
				 break;
			case '6':break; //Exit
			default:{	//Invalid choice
					cout << "\n---------------------------------------------\n" << endl;
					cout << "Invalid chocie. Please try again" << endl;
					cout << "\n---------------------------------------------\n" << endl;
				}
		};
	
	}while(choice != '6');
	
	cout << "\n---------------------------------------------" << endl;	
	cout << "Thank you for using the program" << endl;
	cout << "---------------------------------------------" << endl;	
}
