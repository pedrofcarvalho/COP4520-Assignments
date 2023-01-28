

#include <iostream> 
#include <vector>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;
using namespace std::chrono;

mutex g_mutex;
const int NUM_OF_THREADS = 8;
const int NUMBER_OF_ELEMENTS = 100000000; // 100 * 100 * 100 
const int STEP = NUMBER_OF_ELEMENTS / NUM_OF_THREADS;

vector<int> primeArr; 

vector<bool> InitializeArr(int len) {
	vector<bool> primeArr(len+1);

	primeArr[0] = false;
	primeArr[1] = false;

	for (int i = 2; i < len + 1; i++) 
		primeArr[i] = true;

	return primeArr;
} 

void SievePrimes(vector<bool> &fullArr, int i_0, int i_1) {

	lock_guard<mutex> guard(g_mutex);

	// Sieve of Eratosthenes logic
	for (int i = i_0; i * i < i_1; i++) {
		if (fullArr[i] == true) {
			// figure out how to pass this as reference to a function later
			for (int j = i * i; j <= i_1; j += i)
				fullArr[j] = false;
		}
	}
}

void showOutput(seconds duration) {

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