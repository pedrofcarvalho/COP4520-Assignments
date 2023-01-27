
#include <iostream> 
#include <vector>
#include <thread>
#include <bits/stdc++.h>

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
	for (int i = multipleNum * multipleNum; i < fullArr.size(); i += multipleNum)
		fullArr[i] = false;
}

vector<int> sievePrimes(vector<bool> fullArr) {

	// array to be returned
	vector<int> primeArr(0);

	// Sieve of Eratosthenes logic
	for (int i = 2; i * i < fullArr.size(); i++) {
		if (fullArr[i] == true) {
			// figure out how to pass this as reference to a function later
			uncheckMultiples(ref(fullArr), i);
		}
	}

	// // insert prime value to vector 
    for (int p = 2; p < fullArr.size(); p++)
        if (fullArr[p])
			primeArr.insert(primeArr.end(), p);

	// return prime number array
	return primeArr;
}

long long ShowPrimeSum(vector<int> primeArr) {
	
	long long sum = 0;

	for (int i = 0; i < primeArr.size(); i++)
		sum += primeArr[i];

	return sum;
}

void TopTenPrimes(vector<int> primeArr) {

	cout << "[";

	for (int i = primeArr.size() - 10; i < primeArr.size() - 1; i++) {
		cout << primeArr[i] << ", ";
	}

	cout << primeArr[primeArr.size() - 1] << "]";
}

// with n = 100,000,000 the result is ~9secs 
int main() {

	int n = 100;

	// checking time block
	auto startTime = high_resolution_clock::now();

	vector<int> primeArr = sievePrimes(initializeArr(N_TEST_VAL));

	// checking time block
	auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stopTime - startTime);
    cout << "Duration: " << duration.count() / 1000000 << "s" << "\n" <<  endl;

	// for (int i = 0; i < primeArr.size(); i++)
	// 	cout << primeArr[i] << endl;

	cout << duration.count() << "s " << primeArr.size() << " " << ShowPrimeSum(primeArr) << " ";
	TopTenPrimes(primeArr);

	return 0;
}