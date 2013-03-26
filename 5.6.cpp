/**
 * careercup 5.6
 * Write a program to swap odd and even bits in an integer 
 * with as few instructions as possible (e.g., bit 0 and bit 
 * 1 are swapped, bit 2 and bit 3 are swapped, and so on).
 */
#include <iostream>

using namespace std;

int swap_odd_even_bits(int num)
{
    int mask1 = 0xaaaaaaaa;     // 101010...
    int mask2 = 0x55555555;     // 010101...
    
    mask1 &= num;
    mask2 &= num;
    
    return ((unsigned)mask1 >> 1) | (mask2 << 1);
}

int main()
{
    cout << hex << swap_odd_even_bits(0xaaaa5555) << endl;
    cout << hex << swap_odd_even_bits(0x1234abcd) << endl;
    
    return 0;
}

