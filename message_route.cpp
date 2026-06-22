#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
int n,m;
void bfs(int tmp,vector<vector<int>> &adj,vector<int> &vis,vector<int> &parent){
    queue<int> q;
    q.push(tmp);
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        for(auto &adjnode:adj[node]){
            if(!vis[adjnode]){
                vis[adjnode]=1;
                q.push(adjnode);
                parent[adjnode]=node;
            }
        }
    }
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
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    vis[1]=1;
    bfs(1,adj,vis,parent);
    vector<int> path;
    path.push_back(n);
    int idx=n;
    while(parent[idx]!=1){
        if(parent[idx]==idx&&idx!=1){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        idx=parent[idx];
        path.push_back(idx);
    }
    cout<<path.size()+1<<endl;
    cout<<"1 ";
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i]<<" ";
    }
    cout<<endl;
    return 0;
}