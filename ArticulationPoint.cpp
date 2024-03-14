#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

void dfs(int node, int parent,vector<int> &dis,vector<int> &low,
unordered_map<int, bool> &visited,unordered_map<int, list<int> > &adj,
vector<int> &ap,int &timer)
{
    visited[node] = true;
    dis[node] = low[node] = timer++;
    int child;

    for(auto nbr: adj[node]){
        if(nbr == parent){
            continue;
        }
        if(!visited[nbr]){

            dfs(nbr,node,dis,low,visited,adj,ap,timer);
            low[node] = min(low[node], low[nbr]);

            if(low[nbr] >= dis[node] && parent != -1){
                ap[node] = 1;
            }
            child++;
        }
        else{
            low[node] = min(low[node], dis[nbr]);
        }
    }
    if(parent == -1 && child > 1){
        ap[node] = 1;
    }


}


int main(){
    
    int n = 5;
    int e = 5;

    vector<pair<int,int> > edges;

    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    unordered_map<int, list<int> > adj;

    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dis(n);
    int timer  = 0;
    vector<int> low(n);
    unordered_map<int, bool> visited;
    vector<int> ap(n,0);

    for(int i=0;i<n;i++){
        dis[i] = -1;
        low[i] = -1;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,-1,dis,low,visited,adj,ap,timer);
        }
    }
    
    cout<<"articulation points are as follows"<<endl;
    for(int i=0;i<n;i++){
        if(ap[i] != 0){
            cout << i <<" ";
        }
    }cout<<endl;

    return 0;
}