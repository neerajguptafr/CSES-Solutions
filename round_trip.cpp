#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
int n,m;
int start,last;
bool dfs(int node,int par,vector<int> &parent,vector<vector<int>> &adj,vector<int> &vis){
    vis[node]=1;
    for(auto adjnode:adj[node]){
        if(!vis[adjnode]){
            parent[adjnode]=node;
            if(dfs(adjnode,node,parent,adj,vis)) return true;
        }else if(adjnode!=par){
            start=adjnode;
            last=node;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(n+1,-1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,-1,parent,adj,vis)){
                vector<int> path;
                path.push_back(start);
                for(int i=last;i!=start;i=parent[i]){
                    path.push_back(i);
                }
                path.push_back(start);
                cout<<path.size()<<endl;
                for(int &x:path) cout<<x<<" ";
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}