
#include <iostream> 
#include <vector>
#include <thread>
#include <fstream>

using namespace std;
using namespace std::chrono;

const int NUMBER_OF_ELEMENTS = 100000000;

vector<bool> initializeArr(int len) {
	vector<bool> primeArr(len+1);

	primeArr[0] = false;
	primeArr[1] = false;

	for (int i = 2; i < len + 1; i++) 
		primeArr[i] = true;

	return primeArr;
} 

vector<int> sievePrimes(vector<bool> fullArr) {

	// array to be returned
	vector<int> primeArr(0);

	// Sieve of Eratosthenes logic
	for (int i = 2; i * i < fullArr.size(); i++) {
		if (fullArr[i] == true) {
			// figure out how to pass this as reference to a function later
			for (int j = i * i; j < fullArr.size(); j += i)
				fullArr[j] = false;
		}
	}

	// insert prime value to vector 
    for (int p = 2; p < fullArr.size(); p++)
        if (fullArr[p])
			primeArr.insert(primeArr.end(), p);

	// return prime number array
	return primeArr;
}

void showOutput(vector<int> primeArr, seconds duration) {

	// Create and open a text file
  	ofstream MyFile("primes.txt");

	long long sum = 0;

	for (int i = 0; i < primeArr.size(); i++)
		sum += primeArr[i];

	MyFile << duration.count() << "s " << primeArr.size() << " " << sum << " ";
	
	MyFile << "[";

	for (int i = primeArr.size() - 10; i < primeArr.size() - 1; i++) {
		MyFile << primeArr[i] << ", ";
	}

	MyFile << primeArr[primeArr.size() - 1] << "]";
}