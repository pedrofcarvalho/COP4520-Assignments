
#include <iostream> 
#include <vector>
#include <thread>

using namespace std;
using namespace std::chrono;

const int N_TEST_VAL = 100000000;

vector<bool> initializeArr(int len) {
	vector<bool> primeArr(len+1);

	primeArr[0] = false;
	primeArr[1] = false;

	for (int i = 2; i < len + 1; i++) 
		primeArr[i] = true;

	return primeArr;
} 

// HOW TO PASS FULLARR AS A REFERENCE ???????
void uncheckMultiples(vector<bool> &fullArr, int multipleNum) {
	for (int i = multipleNum; i < fullArr.size(); i += multipleNum)
		fullArr[i] = false;
}

vector<int> sievePrimes(int N) {

	int isPrime;

	// array to be returned
	vector<int> primeArr(0);

	// Sieve of Eratosthenes logic
	for (int i = 2; i < N; i++) 
	{
        isPrime = 0;
        // Check whether i is prime or not
        for(int j = 2; j <= i/2; j++) 
		{
        	// Check If any number between 2 to i/2 divides I 
            // completely If yes the i cannot be prime number
            if(i % j == 0) 
			{
                isPrime = 1;
                break;
            }
        }

		if(isPrime==0 && N!= 1)
			primeArr.insert(primeArr.end(), i);
	}

	// return prime number array
	return primeArr;
}



// with n = 100,000,000 the result is ~9secs 
int main() {

	int n = 100000000;

	// checking time block
	auto startTime = high_resolution_clock::now();

	vector<int> primeArr = sievePrimes(n);

	// checking time block
	auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    cout << "Duration: " << duration.count() / 1000000 << "s" << "\n" << endl;

	// for (int i = 0; i < primeArr.size(); i++)
	// 	cout << primeArr[i] << endl;

	return 0;
}