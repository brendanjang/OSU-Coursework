/*****************************************************************************
** Program Name:	Lab 10 (main.cpp)
** Author:			Brendan Jang
** Date:			3/16/2019
** Description:		Main program file to measure and compare the running time
					of recursive and iterative implementations of Fibonacci
					Numbers Calculation.
*****************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


uint64_t recursion(uint64_t N);
uint64_t iteration(uint64_t N);


int main(int argc, char** argv) {
    clock_t t;
    
    cout << setw(6) << "N" << setw(16) << "recursion"
            << setw(16) << "iteration" << "\n";
    for (uint64_t i = 5; i < 40; i += 5) {
        cout << setw(6) << i ;
        t = clock();
        for (int j = 0; j < 100; j++) {
            recursion(i);
        }        
        cout << setw(16) << clock() - t;
        t = clock();
        for (int j = 0; j < 100; j++) {
            iteration(i);
        }        
        cout << setw(16) << clock() - t << "\n";        
    }
    
    return 0;
}

/**
 * recursive version of fibonacci's algorithm
 * @param N
 * @return 
 */
uint64_t recursion(uint64_t N) {
    if (N < 2) {
        return N;
    }
    return recursion(N - 1) + recursion(N - 2);
}

/**
 * iterative version of fibonacci's algorithm
 * @param N
 * @return 
 */
uint64_t iteration(uint64_t N) {
    if (N < 2) {
        return N;
    }
    
    uint64_t fib = 1;
    uint64_t prev = 1;
    uint64_t tmp;
    
    for (uint64_t i = 2; i < N; i++) {
        tmp = fib;
        fib += prev;
        prev = tmp;
    }
    return fib;
}
