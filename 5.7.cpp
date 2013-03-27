/**
 * careercup 5.7
 * An array A contains all the integers from 0 to n, except for 
 * one number which is missing. In this problem, we cannot access
 * an entire integer in A with a single operation. The elements 
 * of A are represented in binary, and the only operation we can 
 * use to access them is "fetch the jth bit of A," which takes 
 * constant time. Write code to find the missing integer. 
 * Can you do it in O(n) time?
 */
#include <iostream>
#include <vector>

using namespace std;

int missing_bit(vector<int> arr, int pos, int limit)
{
    //cout << "In missing_bit(arr, " << pos << ", " << limit << "): ";
    if (pos > limit) {  // end of recursion
        //cout << "base & error case, return 0." << endl;
        return 0;
    }
    
    vector<int> ones, zeros;
    for (int i = 0; i < arr.size(); i++) {
        if ((arr[i] >> pos) & 1)
            ones.push_back(arr[i]);
        else
            zeros.push_back(arr[i]);
    }
    
    //cout << "ones #: " << ones.size() << ", zeros #: " 
    //   << zeros.size();
    if (ones.size() >= zeros.size()) {  // missing integer has 0 of this bit
        //cout << ". Goto zeros." << endl;
        return (missing_bit(zeros, pos + 1, limit) << 1) | 0;
    } else {
        //cout << ". Goto ones." << endl;
        return (missing_bit(ones, pos + 1, limit) << 1) | 1;
    }
}

int find_int(vector<int> arr, int n)
{
    int base = 1, limit = 0;
    
    if (!n)
        return -1;      // empty!
    
    while (base < n) {
        base <<= 1;
        limit++;
    }
    
    return missing_bit(arr, 0, limit);
}

int main()
{
    int arr[7] = {0, 1, 2, 3, 4, 6, 7}; // missing 5
    vector<int> myints(arr, arr + 7);
    
    cout << find_int(myints, 7) << endl;
    
    return 0;
}
