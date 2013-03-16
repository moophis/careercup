/**
 * careercup 4.6
 * Write an algorithm to find the ¡®next¡¯ node (i.e., in-order successor) 
 * of a given node in a binary search tree. You may assume that each
 * node has a link to its parent.
 */
#include <iostream>

using namespace std;

typedef struct _treenode {
    int key;
    int depth;
    _treenode *left, *right, *parent;
}treenode;

treenode *find_next(treenode *now)
{
    treenode *next = now;
    
    if (!now)
        return NULL;
        
    if (!next->right) {
        if (!next->parent) // root
            return NULL;
        if (next->parent->left && next->parent->left == next)
            return next->parent;
            
        /* Be careful about this part: if this node is 
           its parent's right child, iteratively go back 
           to the parent node until find a parent node  
           which is on the right of the "now" node. 
           If there is no such a parent node, that means
           the "now" node this the last node. Remember that
           the parent of root node is NULL, so returning 
           next->...->parent is just fine */
        while (next->parent && next->parent->right 
                  && next->parent->right == next) {
            next = next->parent;
        }
        return next->parent;
    } else {
        next = next->right;
        while (next->left)
            next = next->left;
    }
    
    return next;
}

int main()
{
    const int node_num = 7;
    treenode mytree[node_num];
    int keys[node_num] = {4, 2, 6, 1, 3, 5, 7};
    
    for (int i = 0; i < node_num; i++)
        mytree[i].key = keys[i];
    mytree[0].left = &mytree[1];
    mytree[0].right = &mytree[2];
    mytree[0].parent = NULL;
    mytree[1].left = &mytree[3];
    mytree[1].right = &mytree[4];
    mytree[1].parent = &mytree[0];
    mytree[2].left = &mytree[5];
    mytree[2].right = &mytree[6];
    mytree[2].parent = &mytree[0];
    for (int i = 3; i <= 6; i++) {
        mytree[i].left = NULL;
        mytree[i].right = NULL;
    }
    mytree[3].parent = mytree[4].parent = &mytree[1];
    mytree[5].parent = mytree[6].parent = &mytree[2];
    
    for (int i = 0; i < node_num; i++) {
        treenode *t = find_next(&mytree[i]);
        if (t) {
            cout << "next node of " << mytree[i].key << " is "
                 << t->key << endl;
        } else {
            cout << "the node " << mytree[i].key
                 << " is the last node!" << endl;
        }
    }
    
    return 0;
}

