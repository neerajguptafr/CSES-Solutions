#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
int n,m;
void bfs(int tmp,vector<vector<int>> &adj,vector<int> &vis){
    queue<int> q;
    q.push(tmp);
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        for(auto &adjnode:adj[node]){
            if(!vis[adjnode]){
                vis[adjnode]=1;
                q.push(adjnode);
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
    vector<int> nodes;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            bfs(i,adj,vis);
            nodes.push_back(i);
        }
    }
    cout<<nodes.size()-1<<endl;
    for(int i=1;i<nodes.size();i++){
        cout<<nodes[i-1]<<" "<<nodes[i]<<endl;
    }
    return 0;
}