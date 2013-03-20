/**
 * careercup 4.9
 * You are given a binary tree in which each node contains a value. 
 * Design an algorithm to print all paths which sum to a given value. 
 * Note that a path can start or end anywhere in the tree.
 */
#include <iostream>
#include <algorithm>
#include <cassert>

#define INF 65535   // infinity number

using namespace std;

typedef struct _treenode {
    int key;        // additional element (ugly)
    int val;
    _treenode *left, *right;
}treenode;

/* data structure: dynamic table used by DP algo. */
typedef struct _dptable {
    int keysum;     // sum of keys
    int valsum;     // sum of values
}dptab_t;

/* 
 * Depth-first search for tree while using dynamic programming:
 * @start: root of the tree to be traversed;
 * @sum: store the values and keys sum of all tree node pairs(initialized);
 * @size: # of nodes in the given tree.
 */
void tree_dfs(treenode *start, dptab_t** sum, const int size)
{
    int nr = start->key;
    assert(nr >= 0 && nr < size);
    
    sum[nr][nr].valsum = start->val;
    sum[nr][nr].keysum = start->key;
    
    if (start->left) {
        int leftval = start->left->val;
        int leftkey = start->left->key;
        
        sum[nr][leftkey].valsum = leftval;
        sum[nr][leftkey].keysum = leftkey;
        
        /* update previous route */
        for (int i = 0; i <= nr; i++) {
            if (sum[i][nr].valsum != INF) {
                sum[i][leftkey].valsum = sum[i][nr].valsum + leftval;
                sum[i][leftkey].keysum = sum[i][nr].keysum + leftkey;
            }
        }
        /* now fork */
        tree_dfs(start->left, sum, size);
    }
    if (start->right) {
        int rightval = start->right->val;
        int rightkey = start->right->key;
        
        sum[nr][rightkey].valsum = rightval;
        sum[nr][rightkey].keysum = rightkey;
        
        /* update previous route */
        for (int i = 0; i <= nr; i++) {
            if (sum[i][nr].valsum != INF) {
                sum[i][rightkey].valsum = sum[i][nr].valsum + rightval;
                sum[i][rightkey].keysum = sum[i][nr].keysum + rightkey;
            }   
        }
        /* now fork */
        tree_dfs(start->right, sum, size);
    }
}

/* print the path from @src to @dst */
void print_path(int src, int dst, dptab_t **table, int size)
{
    if (src < 0 || src > size || dst < 0 || dst > size) {
        cerr << "Wrong argument!" << endl;
        return;
    }
    if (src > dst) 
        swap(src, dst);     
    if (table[src][dst].valsum == INF) {
        cerr << "Cannot find a path from " << src << " to" 
             << dst << endl;
        return;
    } 
    
    /* main part */
    if (src != dst) {
        int nexthop = table[src][dst].keysum - dst;
        int next;
        for (int i = dst; ; i--) {
            if (table[src][i].keysum == nexthop) {
                next = i;
                break;
            }   
        }
        print_path(src, next, table, size);
    }
    cout << dst << "(" << table[src][dst].valsum << ") ";
}

/* find a path where sum of each node equals to @given value */
bool has_path(int given, treenode *root, const int size)
{
    dptab_t **sum;
    sum = new dptab_t*[size];
    for (int i = 0; i < size; i++)
        sum[i] = new dptab_t[size];
        
    /* initialize */
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum[i][j].valsum = INF;
            sum[i][j].keysum = INF;
        }
    }
    
    /* run the algorithm and make the dynamic table*/
    tree_dfs(root, sum, size);
    
#if 0
    /* show the table */
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << sum[i][j].valsum << "\t";
        }
        cout << endl;
    }
    cout << "---------------------------" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << sum[i][j].keysum << "\t";
        }
        cout << endl;
    }
#endif  
    
    /* find and print the path(s) according to the table */
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (sum[i][j].valsum == given) {
                cout << "Path exits: " << i << " " << j << ": ";
                print_path(i, j, sum, size);
            }
        }
    }

    for (int i = 0; i < size; i++)
        delete[] sum[i];
    delete[] sum;
}

int main()
{
    const int size = 8;
    treenode mytree[size] = {
        {0, 1, &mytree[1], &mytree[2]},
        {1, 1, &mytree[3], &mytree[4]},
        {2, 1, &mytree[5], &mytree[6]},
        {3, 1, NULL, NULL},
        {4, 1, NULL, NULL},
        {5, 1, NULL, &mytree[7]},
        {6, 1, NULL, NULL},
        {7, 1, NULL, NULL},
    };
    
    has_path(4, &mytree[0], size);
    
    return 0;
}

