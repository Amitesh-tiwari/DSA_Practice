Problem statement
A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.

Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge 
from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. 
Topological Sorting for a graph is not possible if the graph is not a DAG.

Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out 
any topological sorting of this DAG. Return an array of size ‘V’ representing 
the topological sort of the vertices of the given DAG.

//code

#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<stack>

void dfs(int node,vector<bool> &visited, stack<int> &s,unordered_map<int,list<int>> &adj){

    visited[node] = 1;
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour,visited,s,adj);
        }
    }

    //imp 
    s.push(node);

}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    //adjacency list print kr rhe h
    unordered_map<int,list<int>> adj;

    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //calling for dfs
    stack<int> s;
    vector<bool> visited(v);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,visited,s,adj);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}