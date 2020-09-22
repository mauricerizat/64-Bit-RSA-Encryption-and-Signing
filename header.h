/*
RSA ENCRYPTION PROGRAM
*/


#include <iostream>
#include <math.h>
#include <time.h>
#include <fstream>
#include <cstdint>

using namespace std;

void keyGen();
bool isInteger(string);
bool isPrime(uint64_t);
uint64_t gcd(uint64_t, uint64_t);
uint64_t aInverseModb(uint64_t, uint64_t);
void writeFile(string, string);
string readFile(string);
void signMessage();
uint64_t modular_mul(uint64_t, uint64_t, uint64_t);
uint64_t modular_pow(uint64_t, uint64_t, uint64_t);
void verifySign();
void encrypt();
void decrypt();
