You have been given an undirected, connected graph of ‘V’ vertices 
(labelled from 0 to V-1) and ‘E’ edges. 
Each edge connecting two nodes 'u' and 'v' has a weight denoting the distance between them.

Your task is to find the shortest path distance from the source node 'S' 
to all the vertices. 
You have to return a list of integers denoting the shortest distance 
between each vertex and source vertex 'S'.

//code

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{

   //printing the adjcacency List
    unordered_map<int, list<pair<int,int> > > adj;

    for(int i=0;i<edges;i++){
       int u = edge[i][0];
       int v = edge[i][1];
       int w = edge[i][2];

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

