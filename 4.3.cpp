/**
 * careercup 4.3
 * Given a sorted (increasing order) array, write an algorithm
 * to create a binary search tree with minimal height.
 */
#include <iostream>
#include <queue>

using namespace std;

typedef struct _treenode {
    int val;
    _treenode *left, *right;
}treenode;

/*
 * Method: Recursively divide array by two to find
 * the root of each subtrees.
 * Input: @arr: input array;
 *        @root: the root of current (balanced) tree;
 *        @begin: begin of the array;
 *        @end: end of the array.
 */
void insert_node(int arr[], treenode* &root, int begin, int end)
{
    int mid = (end - begin) / 2 + begin;
    
    root = new treenode;
    root->val   = arr[mid];
    root->left  = NULL;
    root->right = NULL;
    
    if ( begin == end )
        return;
    if ( begin + 1 != end )  // special case: when nodes # is even
        insert_node(arr, root->left, begin, mid - 1);
    insert_node(arr, root->right, mid + 1, end);
}

/* traverse the tree in level order */
void traverse(treenode* &root)
{
    queue<treenode *> buf;
    
    if ( root == NULL )
        return;
    
    buf.push(root);
    while ( !buf.empty() ) {
        treenode *tmp = buf.front();
        buf.pop();
        
        // show some stats...
        cout << "Value " << tmp->val << " has:";
        if ( tmp->left )
            cout << " left child: " << tmp->left->val;
        if ( tmp->right )
            cout << " right child: " << tmp->right->val;
        if ( !tmp->left && !tmp->right )
            cout << " no child";
        cout << endl;
        
        if ( tmp->left ) 
            buf.push(tmp->left);
        if ( tmp->right ) 
            buf.push(tmp->right);
    }
}

int main()
{
    const int array_size = 8;
    int arr[array_size];
    treenode *root;
    
    for (int i = 0; i < array_size; i++) 
        arr[i] = i;
    
    insert_node(arr, root, 0, array_size - 1);
    traverse(root);

    return 0;
}
