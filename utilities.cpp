/*
RSA ENCRYPTION PROGRAM
*/

#include "header.h"

//Wites given content to given file
void writeFile(string content, string fileName)
{
	ofstream fileWriter;
	fileWriter.open ("data/" + fileName);
	fileWriter << content << endl;
	fileWriter.close();
}

//Reads from given file and returns corresponding content
string readFile(string fileName)
{
	string content = "";
	
	ifstream fileReader("data/" + fileName); //File to be located in "data" sub-folder
	if (!(fileReader.is_open())) //Input file cannot be opened or does not exist
	{
		cout << "\n\tFile named \"" << fileName;
		cout << "\" cannot be opened or does not exist.";
		cout << "\n\tPlease try again with a valid file name.\n" << endl;
		return 0;
	}	
	else //Input file exists
	{			
		//Reading Input file
		try 
		{
			string line;
			while (getline(fileReader, line))
				content += (line + "\n");
			
			content = content.substr(0, content.size()-1);
			
		fileReader.close();
		} 
		catch (exception& e) //Handles errors that occurs during file reading
		{
			cout << "An error occured while reading file. Please try again.\n" << endl;
			return 0;
		}
	}
	
	return content;
}

//Calculate inverse of a modulo b using Extended Euclidean Algorithm
uint64_t aInverseModb(uint64_t a, uint64_t b)
{
	uint64_t n1 = b;
	uint64_t n2 = a;
	
	long long int a1 = 1;
	long long int b1 = 0;
	long long int a2 = 0;
	long long int b2 = 1;
	
	long long int q = n1 / n2;
	long long int r = n1 % n2;
	
	while (r > 0)
	{
		n1 = n2;
		n2 = r;
		
		long long int t = a2;
		a2 = a1 - q*a2;
		a1 = t;
		
		t = b2;
		b2 = b1 - q*b2;
		b1 = t;
		
		q = n1 / n2;
		r = n1 % n2;	
	}
	
	if (b2 < 0)
		b2 = b + b2;
	
	return b2;
}

//Calculate gcd or two values using Euclidean Algorithm
uint64_t gcd(uint64_t a, uint64_t b)
{
	if (a == 0 || b == 0)
		return 0;
	
	if (a < b)
	{
		uint64_t t = a;
		a = b;
		b = t;
	}
	
	uint64_t rem = a%b;
	
	while (rem > 0)
	{
		a = b;
		b = rem;
		rem = a % b;
	}

	return b;
	
}

//Check if given number is prime
bool isPrime(uint64_t n)
{
	if (n == 1 || n == 0)
		return false;
	
	for (int i = 2; i <= pow(n, 0.5); ++i)
	{
		if (n%i == 0)
			return false;
	}
	
	return true;
}

//Check if given string contains only Integers
bool isInteger(string num)
{
	for (int i = 0; i < num.length(); ++i)
	{
		if (num[i] < '0' || num[i] > '9')
			return false;
	}
	
	return true;
}

//Perform modular multiplication
uint64_t modular_mul(uint64_t a, uint64_t b, uint64_t mod) 
{
	uint64_t result = 0;
	
	for (uint64_t current_term = a; b; b >>= 1) 
	{
		if (b & 1) 
		{
			result = (result + current_term) % mod;
		}
		
		current_term = 2 * current_term % mod;
	}
	return result;
}

//Perform modular exponentiation
uint64_t modular_pow(uint64_t base, uint64_t exp, uint64_t mod) 
{
	uint64_t result = 1;
	for (uint64_t current_factor = base; exp; exp >>= 1) 
	{
		if (exp & 1) 
		{
			result = modular_mul(result, current_factor, mod);
		}
		current_factor = modular_mul(current_factor, current_factor, mod);
	}
	return result;
}










