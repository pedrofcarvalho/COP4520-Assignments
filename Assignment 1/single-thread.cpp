
#include "singlet-func.h"

using namespace std;
using namespace std::chrono;

int main() {

	// checking time block
	auto startTime = high_resolution_clock::now();

	// actual logic implementation
	vector<int> primeArr = sievePrimes(initializeArr(NUMBER_OF_ELEMENTS));

	// checking time block
	auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stopTime - startTime);

	// write info to primes.txt file
	showOutput(primeArr, duration);

	return 0;
}