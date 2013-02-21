/* 
 * Given an image represented by an NxN matrix, 
 * where each pixel in the image is 4 bytes, write 
 * a method to rotate the image by 90 degrees. 
 * Can you do this in place?
 */
#include <iostream>

using namespace std;

void rotate90(int **A, const int size)
{
    // buffer the pixles firstly to be overwritten
    int buffer; 
    // # of loops to be dealt with
    int loop = size / 2;
    // # of initially spinned number
    int initnum = size - 1;
    
    for (int i = 0; i < loop; i++) {
        for (int j = i; j < i + initnum; j++) {
            // rotate one number with its three counterparts
            buffer = A[j][i];
            A[j][i] = A[size - 1 - i][j];
            A[size - 1 - i][j] = A[size - 1 - j][size - 1 - i];
            A[size - 1 - j][size - 1 - i] = A[i][size - 1 - j];
            A[i][size - 1 - j] = buffer;
        }
        initnum -= 2;
    }
    
    // test results
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    const int N = 5;
    int count = 1;
    int **mat;
    
    mat = new int*[N];
    for (int i = 0; i < N; i++)
        mat[i] = new int[N];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = count++;
    rotate90(mat, N);
    
    for (int i = 0; i < N; i++)
        delete[] mat[i];
    delete[] mat;
    
    return 0;
}