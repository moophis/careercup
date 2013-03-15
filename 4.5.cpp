/**
 * careercup 4.5
 * Implement a function to check if a binary 
 * tree is a binary search tree.
 */
#include <iostream>

/* two sentinels */
#define PLUS_INF  65535
#define MINUS_INF -65536

using namespace std;

typedef struct _treenode {
    int key;
    int depth;
    _treenode *left, *right;
}treenode;

/*
 * Method: Recursively check each node with its children 
 * if it has any, while updating the upper bound and lower 
 * bound of possible value its children in a BST should have. 
 * Input: @cur_root: current root of the subtree;
 *        @lower: lower bound the value of children of current node
 *                should meet;
 *        @upper: upper bound ...
 */
bool do_check_bst(treenode *cur_root, int lower, int upper)
{
    // bottom of the tree
    if (!cur_root) 
        return true;

    // now do comparing work
    if (cur_root->left != NULL && 
         (cur_root->left->key > cur_root->key 
           || cur_root->left->key < lower)) 
        return false;
    if (cur_root->right != NULL && 
         (cur_root->right->key < cur_root->key
           || cur_root->right->key > upper))
        return false;
    
    return do_check_bst(cur_root->left, lower, cur_root->key)
              && do_check_bst(cur_root->right, cur_root->key, upper);
}

bool check_bst(treenode *root)
{
    return root == NULL ? false 
      : (do_check_bst(root->left, MINUS_INF, root->key) 
           && do_check_bst(root->right, root->key, PLUS_INF));
}

int main()
{
    const int node_num = 7;
    treenode mytree[node_num];
    int keys1[node_num] = {4, 2, 6, 1, 3, 1, 7}; // false
    int keys[node_num] = {4, 2, 6, 1, 3, 5, 7}; // true
    
    for (int i = 0; i < node_num; i++)
        mytree[i].key = keys[i];
    mytree[0].left = &mytree[1];
    mytree[0].right = &mytree[2];
    mytree[1].left = &mytree[3];
    mytree[1].right = &mytree[4];
    mytree[2].left = &mytree[5];
    mytree[2].right = &mytree[6];
    for (int i = 3; i <= 6; i++) {
        mytree[i].left = NULL;
        mytree[i].right = NULL;
    }
    
    cout << check_bst(&mytree[0]) << endl;
    
    return 0;
}
