Problem statement
You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' 
and ‘M’ edges. Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting 
the distance between them.

Your task is to calculate the shortest distance of all 
vertices from the source vertex 'src'.

//code

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    
    vector<int> dist(n+1,1e8);
    dist[src] = 0;

    //n-1 times iterating
    for(int i=1;i<n;i++){
        for(int j= 0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])){
                dist[v] = dist[u] + wt;
            }

        }
    }
    return dist;

}

