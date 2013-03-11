/**
 * careercup 4.1
 * Implement a function to check if a binary tree is balanced. 
 * For the purposes of this question, a balanced tree is defined 
 * to be a tree such that the heights of the two subtrees of 
 * any node never differ by more than one.
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef struct _node {
    _node *left;
    _node *right;
}treenode;

/*
 * Method: recursively check if a binary tree is balanced.
 * Input: @current: regard current node as the root of a 
 *                  tree.
 *        @max_height: the height between this root and
 *                     the deepest leave (provided by this
 *                     function call).
 * Output: return if the tree with root @current is balanced.
 */
bool balanced(treenode *current, int &max_height)
{
    int left_height, right_height;
    bool last_balance;
    
    // exiting scenario: current root is a leaf
    if ( !current ) {
        max_height = 0;
        return true;
    }
    
    last_balance = balanced(current->left, left_height)
                    && balanced(current->right, right_height);
    max_height = max(left_height, right_height) + 1;
    
    return last_balance && abs(left_height - right_height) <= 1;
}

/*
 * Method: A non-recursive way which for each iteration harness 
 * a vector to store each node while counting minimum height of
 * the tree. 
 */
bool balanced_nr(treenode *root)
{
    int min_height = 65536, max_height = 0;
    // vector of pointers to each node in the same depth.
    vector<treenode *> thislevel;
    bool no_child = false;
    
    if ( !root )
        return true;
		
    thislevel.push_back(root);
    for (int cur_height = 0; !no_child; cur_height++) {
        int cur_size = thislevel.size();
        no_child = true;
        
        for (int i = 0; i < cur_size; i++) {
            treenode *cur_node = thislevel[i];
    
            if ( !cur_node->left && !cur_node->right ) {
                thislevel.erase(thislevel.begin() + i);
                min_height = min(min_height, cur_height);
                cur_size--;
                i--;
            } else {
                no_child = false;
                if ( cur_node->left ) 
                    thislevel[i] = cur_node->left;
                if ( cur_node->right && cur_node->left ) 
                    thislevel.push_back(cur_node->right);
                else 
                    thislevel[i] = cur_node->right;
            }
            
            //min_height = min(min_height, cur_height);
            max_height = cur_height;
            if ( max_height - min_height > 1 )
                return false;
        }
    }
    
    return max_height - min_height <= 1;
}

int main()
{
    int height;
    treenode tree[6];
    
    /*
     * test case:
     *     0
          / \
         1   2
            / \
           3  4
               \
                5
     */
    tree[0].left  = &tree[1];
    tree[0].right = &tree[2];
    tree[1].left  = tree[1].right = NULL;
    tree[2].left  = &tree[3];
    tree[2].right = &tree[4];
    tree[3].left  = tree[3].right = NULL;
    tree[4].left  = NULL;
    tree[4].right = &tree[5];;
    tree[5].left  = tree[5].right = NULL;
    
    cout << "This tree is ";
    if ( !balanced(&tree[0], height) )
        cout << "not ";
    cout << "a balanced tree!" << endl;
    
    cout << "This tree is ";
    if ( !balanced_nr(&tree[0]) )
        cout << "not ";
    cout << "a balanced tree!" << endl;
    
    return 0;
}

