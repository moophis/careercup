/**
 * Write an algorithm such that if an element 
 * in an MxN matrix is 0, its entire row and 
 * column are set to 0.
 */
 
#include <iostream>
#include <vector>

using namespace std;

const int ROW = 5;
const int COL = 4;

/*
 * data structure for 0 element
 */
struct zpoint {
    int col;
    int row;
};

void setzero(int **mat, int rowsize, int colsize)
{
    int row_now, col_now;
    struct zpoint tmp;
    vector<struct zpoint> zp;
    // first figure out where the 0 elements are
    for (int row = 0; row < rowsize; row++) {
        for (int col = 0; col < colsize; col++) {
            if ( !mat[row][col] ) {
                tmp.col = col;
                tmp.row = row;
                zp.push_back(tmp);
            }
        }
    }
    
    // then set 0 to elements related to 0 elements
    for (int i = 0; i < zp.size(); i++) {
        col_now = zp[i].col;
        for (int row = 0; row < rowsize; row++)
            mat[row][col_now] = 0;
        
        row_now = zp[i].row;
        for (int col = 0; col < colsize; col++)
            mat[row_now][col] = 0;
    }
}

/*
 * test case
 */
int main()
{
    int **t;
    
    t = new int*[ROW];
    for (int i = 0; i < ROW; i++) {
        t[i] = new int[COL];
        for (int j = 0; j < COL; j++)
            t[i][j] = 1;
    }
        
    t[2][3] = 0;
    t[0][0] = 0;
    
    setzero(t, ROW, COL);
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) 
            cout << t[i][j] << " ";
        cout << endl;
    }
    
    for (int i = 0; i < ROW; i++)
        delete[] t[i];
    delete[] t;
    
    return 0;
}