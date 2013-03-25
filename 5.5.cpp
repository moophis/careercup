/**
 * careercup 5.5
 * Write a function to determine the number of bits 
 * required to convert integer A to integer B.
 *
 * EXAMPLE:
 * Input:31,14
 * Output:2
 */
#include <iostream>

using namespace std;

int conv_bits(int a, int b)
{
    int cnt = 0, mask = 1;
    int result = a ^ b;
    
    for (int i = 0; i < 32; i++) {
        if (result & mask)
            cnt++;
        mask <<= 1;
    }
    
    return cnt;
}

int main()
{
    cout << conv_bits(31, 14) << endl;
    
    return 0;
}
