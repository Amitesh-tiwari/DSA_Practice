Problem statement
Given an adjacency list representation of a directed graph with ‘n’ vertices and ‘m’ edges. 
Your task is to return a list consisting of Breadth-First Traversal (BFS) starting from vertex 0.

In this traversal, one can move from vertex 'u' to vertex 'v' only if there is an edge from 'u' to 'v'.
 The BFS traversal should include all nodes directly or indirectly connected to vertex 0.

 //code

 #include<queue>

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    
    vector<int> res;
    queue<int> q;
    
    q.push(0);
    vector<int> vis(n,0);

    vis[0] = 1;

    while(!q.empty()){
        int topVertex = q.front();
        q.pop();

        res.push_back(topVertex);

        for(auto neighbor : adj[topVertex]){
            if(!vis[neighbor]){
                vis[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
    return result;
}
