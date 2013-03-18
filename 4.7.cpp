/**
 * careercup 4.7
 * Design an algorithm and write code to find the first 
 * common ancestor of two nodes in a binary tree. 
 * Avoid storing additional nodes in a data structure. 
 * NOTE: This is not necessarily a binary search tree.
 */
#include <iostream>

using namespace std;

typedef struct _treenode {
    int key;
    _treenode *left, *right;
}treenode;

treenode *first_common_ancestor(treenode *root, treenode *p, treenode *q)
{
    if (!root) 
        return NULL;
    //cout << endl << ">> root->key = " << root->key << ", ";
        
    if (root->left == p || root->left == q
         || root->right == p || root->right == q) {
        //cout << "returning root..." << endl;
        return root;
    } else {
        //cout << "going downward..." << endl;
        treenode *l = first_common_ancestor(root->left, p, q);
        treenode *r = first_common_ancestor(root->right, p, q);
        /* p and q in different subtrees, so return the
           first common ancestor of them */
        if (l && r) {
            //cout << "<< root->key = " << root->key << ", p and q in this subtree" << endl; 
            return root;
        }
        //cout << "<< root->key = " << root->key << ", p and q not in this subtree" << endl; 
        return l ? l : r;
    }
}

int main()
{
    const int node_num = 8;
    treenode mytree[node_num];
    
    for (int i = 0; i < node_num; i++)
        mytree[i].key = i;
    mytree[0].left = &mytree[1];
    mytree[0].right = &mytree[2];
    mytree[1].left = &mytree[3];
    mytree[1].right = &mytree[4];
    mytree[2].left = &mytree[5];
    mytree[2].right = &mytree[6];
    mytree[3].left = &mytree[7];
    mytree[3].right = NULL;
    for (int i = 4; i <= 7; i++) {
        mytree[i].left = NULL;
        mytree[i].right = NULL;
    }
    
    cout << "First common ancestor of 3 and 7: " 
         << first_common_ancestor(&mytree[0], &mytree[3], &mytree[7])->key 
         << endl;
}
