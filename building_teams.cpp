#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
int n,m;
bool flag=false;
void bfs(int tmp,vector<vector<int>> &adj,vector<int> &vis){
    queue<int> q;
    q.push(tmp);
    vis[tmp]=1;
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        for(auto &adjnode:adj[node]){
            if(!vis[adjnode]){
                vis[node]==1?vis[adjnode]=2:vis[adjnode]=1;
                q.push(adjnode);
            }else if(vis[adjnode]==vis[node]){
                flag=true;
                return;
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
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bfs(i,adj,vis);
            if(flag){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<vis[i]<<" ";
    }
    cout<<endl;
    return 0;
}