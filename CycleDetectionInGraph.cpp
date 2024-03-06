Problem statement
You have been given an undirected graph with 'N' vertices and 'M' edges. 
The vertices are labelled from 1 to 'N'.

Your task is to find if the graph contains a cycle or not.
A path that starts from a given vertex and ends at the same vertex traversing 
the edges only once is called a cycle.

//code

#include<unordered_map>
#include<list>
#include<queue>


bool isCyclic(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj){

    unordered_map<int,int> parent;
    parent[src] = 1;
    visited[src] = 1;

    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbor : adj[front]){
            if(visited[neighbor] == true &&  neighbor!= parent[front]){
                return true;
            }
            else if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = front;
            }
        }
    }
    return false;

}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int> > adj;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }

    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans  = isCyclic(i,visited,adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}
