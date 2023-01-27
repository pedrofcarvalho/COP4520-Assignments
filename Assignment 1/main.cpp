// Your First C++ Program

#include <iostream>
#include "functions.h"
#include <thread>
#include <map>
#include <string>   

using namespace std;

void salve(ostream& o = cout) { 

    o << "[";

    for (int i = 0; i < 10; i++) {
        o << i << " ";
    }

    o << "10]" << endl;
}

int main(int argc, char* argv[]) 
{

    salve();

    // cout << ola << endl;

    // system("pause>nul");

    return 0;
}