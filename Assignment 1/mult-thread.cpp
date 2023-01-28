
#include "mult-func.h"

using namespace std;
using namespace std::chrono;

int main() 
{
	// initialize vectors
	vector<thread> threads;
	vector<bool> fullArr = InitializeArr(NUMBER_OF_ELEMENTS);

	// start checking time
	auto startTime = high_resolution_clock::now();

	// creating threads
	for (int currT = 1; currT <= NUM_OF_THREADS; currT++)
	{
		int i_0 = STEP * (currT-1);
		int i_1 = STEP * currT;

		if (i_0 == 0)
			i_0 = 2;
		
		threads.push_back(thread(SievePrimes, ref(fullArr), i_0, i_1));
	}

    // waiting for all of them to finish
    for (auto& th : threads) 
		if (th.joinable())
			th.join();   // Running code


	// checking time block
	auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stopTime - startTime);

	for (int p = 2; p < fullArr.size(); p++) {
        if (fullArr[p])
			primeArr.insert(primeArr.end(), p);
	}

	// write info to output file
	showOutput(duration);

	return 0;
}