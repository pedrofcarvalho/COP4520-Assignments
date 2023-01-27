
#include <iostream> 
#include <vector>
#include <thread>
#include <mutex>

using namespace std;
using namespace std::chrono;


mutex g_mutex;
const int NUM_OF_THREADS = 8;
const int NUMBER_OF_ELEMENTS = 100000000; // 100 * 100 * 100 
const int STEP = NUMBER_OF_ELEMENTS / NUM_OF_THREADS; // MAKE THIS A CONST

vector<int> primeArr(0);
vector<bool> fullArr(0);

vector<bool> InitializeArr(int len) {
	vector<bool> primeArr(len+1);

	primeArr[0] = false;
	primeArr[1] = false;

	for (int i = 2; i < len + 1; i++) 
		primeArr[i] = true;

	return primeArr;
} 

// HOW TO PASS FULLARR AS A REFERENCE ???????
void UncheckMultiples(vector<bool> &fullArr, int multipleNum) {
	for (int i = multipleNum * multipleNum; i < fullArr.size(); i += multipleNum)
		fullArr[i] = false;
}

void SievePrimes(vector<bool> fullArr, int i_0, int i_1) {

	lock_guard<mutex> guard(g_mutex);

	// Sieve of Eratosthenes logic
	for (int i = i_0; i * i <= i_1; i++) {
		if (fullArr[i] == true) {
			// figure out how to pass this as reference to a function later
			UncheckMultiples(ref(fullArr), i);
		}
	}

	// insert prime value to vector 
    for (int p = 2; p < fullArr.size(); p++)
        if (fullArr[p])
			primeArr.insert(primeArr.end(), p);
}

long long ShowPrimeSum() {
	
	long long sum = 0;

	for (int i = 0; i < primeArr.size(); i++)
		sum += primeArr[i];

	return sum;
}

void TopTenPrimes() {

	cout << "[";

	for (int i = primeArr.size() - 10; i < primeArr.size() - 1; i++) {
		cout << primeArr[i] << ", ";
	}

	cout << primeArr[primeArr.size() - 1] << "]";
}

int main() 
{
	// const int n = 100000000;
	// const int STEP = n / NUM_OF_THREADS;

	fullArr = InitializeArr(NUMBER_OF_ELEMENTS);
	vector<thread> threads;

	cout << "Creating all threads...\n" << endl;

	// start checking time
	auto startTime = high_resolution_clock::now();


	for (int currT = 1; currT <= NUM_OF_THREADS; currT++)
	{
		int i_0 = STEP * (currT-1);
		int i_1 = STEP * currT;

		if (i_0 == 0)
			i_0 = 2;

		// cout << "On iteration " << currT << ":" << endl;
		// cout << "i_0 = " << i_0 << endl;
		// cout << "i_1 = " << i_1 << endl;
		// cout << endl;

		// for (int i = 0; i < fullArr.size(); i++)
		// 	cout << fullArr[i];
		// cout << endl;
		
		threads.push_back(thread(SievePrimes, fullArr, i_0, i_1));
	}

	// thread t1(SievePrimes, fullArr, 0, 12500000);
	// thread t2(SievePrimes, fullArr, 12500000, 25000000);
	// thread t3(SievePrimes, fullArr, 25000000, 37500000);
	// thread t4(SievePrimes, fullArr, 37500000, 50000000);
	// thread t5(SievePrimes, fullArr, 50000000, 62500000);
	// thread t6(SievePrimes, fullArr, 62500000, 75000000);
	// thread t7(SievePrimes, fullArr, 75000000, 87500000);
	// thread t8(SievePrimes, fullArr, 87500000, 100000000);

	// t1.join();
	// t2.join();
	// t3.join();
	// t4.join();
	// t5.join();
	// t6.join();
	// t7.join();
	// t8.join();

    cout << "Synchronizing all threads...\n" << endl;
    for (auto& th : threads) 
		if (th.joinable())
			th.join();   // Running code


	// checking time block
	auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stopTime - startTime);
    // cout << "Duration: " << duration.count() << "s" << endl;


	cout << duration.count() << "s " << primeArr.size() << " " << ShowPrimeSum() << " ";
	TopTenPrimes();


	return 0;
}