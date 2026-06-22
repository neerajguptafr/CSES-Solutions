#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
int n,m;
void bfs(int r,int c,vector<vector<char>> &v,vector<vector<int>> &vis){
    queue<pi> q;
    q.push({r,c});
    while(!q.empty()){
        auto [a,b]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr=a+dr[i];
            int nc=b+dc[i];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&!vis[nr][nc]&&v[nr][nc]=='.'){
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(auto &x:v){
        for(auto &y:x) cin>>y;
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    return 0;
}