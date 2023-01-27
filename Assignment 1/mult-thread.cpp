
#include "mult-func.h"

using namespace std;
using namespace std::chrono;


// vector<int> primeArr(0);
// vector<bool> fullArr(0);

int main() 
{
	vector<bool> fullArr = InitializeArr(NUMBER_OF_ELEMENTS);
	vector<int> primeArr;

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
		
		threads.push_back(thread(SievePrimes, ref(primeArr), ref(fullArr), i_0, i_1));
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

	for (int p = 2; p < fullArr.size(); p++)
        if (fullArr[p])
			primeArr.insert(primeArr.end(), p);


	showOutput(primeArr, duration);


	return 0;
}