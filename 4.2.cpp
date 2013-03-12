/**
 * careercup 4.2
 * Given a directed graph, design an algorithm to find out
 * whether there is a route between two nodes.
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * Data structure: graph node
 */
typedef struct _gnode {
    int index;
    bool visited;
    vector<_gnode *> adj;
}gnode;

/*
 * Method: using breadth-first search.
 * Input: @src: pointer to source node;
 *        @dst: pointer to destination node.
 * Output: whether there is a route between 
 *         two nodes.
 */
bool bfs(gnode* &src, gnode* &dst)
{
    queue<gnode *> buf;
    
    buf.push(src);
    
    while ( !buf.empty() ) {
        gnode *next = buf.front();
        buf.pop();
        
        for (int i = 0; i < next->adj.size(); i++) {
            if ( next->adj[i] == dst )
                return true;
            buf.push(next->adj[i]);
        }
    }
    
    return false;
}

/*
 * Method: using depth-first search.
 */
bool dfs_visit(gnode* &src, gnode* &dst)
{
    bool retval = false;
    
    src->visited = true;
    for (int i = 0; i < src->adj.size(); i++) {
        if ( src->adj[i] == dst )
            return true;
        if ( !src->adj[i]->visited ) {
            cout << "Next hop: " << src->adj[i]->index << endl;
            retval = dfs_visit(src->adj[i], dst);
        }
    }
    
    return retval;
}

/*
 * @graph: the input graph;
 * @gnode_size: number of nodes in the graph.
 */
bool dfs(gnode* &src, gnode* &dst, gnode** graph, int gnode_size)
{
    for (int i = 0; i < gnode_size; i++) {
        graph[i]->visited = false;
    }
    
    src->visited = true;
    return dfs_visit(src, dst);
}

int main()
{
    gnode **mygraph;
    const int gnum = 7;
    
    mygraph = new gnode* [gnum];
    for (int i = 0; i < gnum; i++) {
        mygraph[i] = new gnode;
        mygraph[i]->index = i;
    }
    mygraph[0]->adj.push_back(mygraph[1]);
    mygraph[0]->adj.push_back(mygraph[2]);
    mygraph[1]->adj.push_back(mygraph[3]);
    mygraph[3]->adj.push_back(mygraph[4]);
    mygraph[2]->adj.push_back(mygraph[4]);
    mygraph[2]->adj.push_back(mygraph[5]);
    mygraph[2]->adj.push_back(mygraph[6]);
    
    cout << bfs(mygraph[0], mygraph[5]) << endl;
    cout << dfs(mygraph[0], mygraph[5], mygraph, gnum) << endl;
    
    return 0;
}

