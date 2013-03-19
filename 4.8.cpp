/**
 * careercup 4.8
 * You have two very large binary trees: T1, with millions of nodes, 
 * and T2, with hundreds of nodes. Create an algorithm to decide 
 * if T2 is a subtree of T1.
 *
 * A tree T2 is a subtree of T1 if there exists a node n in T1 
 * such that the subtree of n is identical to T2. That is, if 
 * you cut the tree at node n, the two trees would be identical.
 */
#include <iostream>

using namespace std;

typedef struct _treenode {
    int key;
    _treenode *left, *right;
}treenode;

bool tree_identical(treenode *t1, treenode *t2)
{
    if (!t1 && !t2)
        return true;    // no more subtress for both trees
    if (!t1 || !t2)
        return false;   // one tree still has subtree
    if (t1->key != t2->key)
        return false;   // key doesn't match
    return tree_identical(t1->left, t2->left) 
            && tree_identical(t1->right, t2->right);
}

bool tree_match(treenode *t1, treenode *t2)
{
    if (!t1)
        return false;   // end of this branch
    if (t1->key == t2->key)
        return tree_identical(t1, t2);
    return tree_match(t1->left, t2)
            || tree_match(t1->right, t2);
}

bool subtree(treenode *t1, treenode *t2)
{
    if (!t2)
        return true;
    return tree_match(t1, t2);
}

int main()
{
    // forgive my laziness
    return 0;
}
