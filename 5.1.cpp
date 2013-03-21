/**
 * careercup 5.1
 * You are given two 32-bit numbers, N and M, and two bit positions, 
 * i and j. Write a method to insert M into N such that M starts at 
 * bit j and ends at bit i. You can assume that the bits j through i 
 * have enough space to fit all of M. That is, if M=10011, you can 
 * assume that there are at least 5 bits between j and i. You would not, 
 * for example, have j = 3 and i=2, because M could not fully fit 
 * between bit 3 and bit 2. 
 * EXAMPLE
 * Input: N = 10000000000, M = 10011, i = 2, j = 6
 * Output: N = 10001001100
 */
#include <iostream>

using namespace std;

unsigned mix_int(unsigned N, unsigned M, int i, int j)
{   
    int mask = 0;
    for (int k = i; k <= j; k++) {
        mask |= (1 << k);
    }
    mask = ~mask;
    N &= mask;
    return N | (M << i);
}

int main()
{
    unsigned N = 0x400, M = 0x13;
    
    // expected 0x44c
    cout << hex << mix_int(N, M, 2, 6) << endl;
    return 0;
}
