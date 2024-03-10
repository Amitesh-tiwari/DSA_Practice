Problem statement
You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) 
and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting
 the distance between node ‘X’ and node ‘Y’.

Your task is to find the shortest path distance from the source node, 
which is the node labeled as 0, to all vertices given in the graph.

//code

#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<set>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
   //printing the adjcacency List
   unordered_map<int, list<pair<int,int> > > adj;

   for(int i=0;i<edges;i++){
       int u = vec[i][0];
       int v = vec[i][1];
       int w = vec[i][2];

       adj[u].push_back(make_pair(v,w));
       adj[v].push_back(make_pair(u,w));
   }

   vector<int> dist(vertices);
   for(int i=0;i<vertices;i++)
     dist[i] = INT_MAX;
    
    set<pair<int,int>> st;
    dist[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){

        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                if(record != st.end()){
                    st.erase(record);

                }

                dist[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
    
}
