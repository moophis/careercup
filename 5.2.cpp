/**
 * careercup 5.2
 * Given a real number between 0 and 1 (e.g., 0.72) that is 
 * passed in as a double, print the binary representation. 
 * If the number cannot be represented accurately in binary 
 * with at most 32 characters, print "ERROR."
 */
#include <iostream>
#include <string>
#include <limits>

using namespace std;

string real_to_bin(double real)
{
    int bitcnt = 1;
    string binnum;
    double cur_real = 0.0;
    double dmin = numeric_limits<double>::min();
    
    if (real - 1.0 > dmin || 0.0 - real > dmin)
        return "INVALID.";
    //if (real - 1.0 < dmin && real - 0.0 > dmin)
    if (real == 1.0)
        return "1.0";
    if (real == 0.0)
        return "0.0";
        
    binnum = "0.";
    while (bitcnt < 32) {
        double cur_part = 1.0 / (double)(1 << bitcnt);
#if 0
        cout << "cur_real:" << cur_real << "part:" << cur_part;
        cout << "cur_real + cur_part - real = "
             << cur_real + cur_part - real << endl;
#endif      
        if (cur_real + cur_part - real > dmin) {
            binnum += "0";
        } else if (cur_real + cur_part == real) {
            return binnum + "1";
        } else if (real - (cur_real + cur_part) > dmin) {
            binnum += "1";
            cur_real += cur_part;
        }
        bitcnt++;
        cout << endl;
    }

    return "ERROR.";
}

int main()
{
    cout << real_to_bin(0.625) << endl;
    return 0;
}