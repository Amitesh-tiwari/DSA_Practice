You are given a directed graph having ‘N’ nodes. 
A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges 
such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].

Find whether the graph contains a cycle or not, 
return true if a cycle is present in the given directed graph else return false.

For Example :
In the following directed graph has a cycle i.e. B->C->E->D->B.

//code

#include<unordered_map>
#include<list>

bool CycleFound(int node, unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,unordered_map<int,list<int>> &adj){

    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour: adj[node]){
      if (!visited[neighbour]) {
        bool cycleDetected = CycleFound(neighbour, visited, dfsVisited, adj);
        if (cycleDetected){
          return true;
        }
      }
      else if (dfsVisited[neighbour]) {
        return true;
      }
    }
    
    dfsVisited[node] = false;
    return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++){
      int u = edges[i].first;
      int v = edges[i].second;

      adj[u].push_back(v);

    }

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;

    for(int i=0;i<n;i++){
      if(!visited[i]){
        bool ans = CycleFound(i,visited,dfsVisited,adj);

        if(ans){
          return true;
        }
      }
    }

    return false;
}