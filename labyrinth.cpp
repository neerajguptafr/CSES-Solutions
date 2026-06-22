#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
char direc[4]={'R','L','D','U'};
int n,m,ans;
vector<vector<pi>> parent;
void bfs(int r,int c,int ea,int eb,vector<vector<char>> &v,vector<vector<int>> &vis,vector<vector<char>> &path){
    queue<pair<pi,int>> q;
    q.push({{r,c},0});
    vis[r][c]=1;
    parent[r][c]={-1e7,-1e7};
    while(!q.empty()){
        auto [p,val]=q.front();
        auto [a,b]=p;
        if(a==ea&&b==eb){
            ans=val;
            return;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nr=a+dr[i];
            int nc=b+dc[i];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&!vis[nr][nc]&&v[nr][nc]!='#'){
                vis[nr][nc]=1;
                q.push({{nr,nc},val+1});
                path[nr][nc]=direc[i];
                parent[nr][nc]={a,b};
            }
        }
    }
}
int main(){
    cin>>n>>m;ans=-1;
    vector<vector<char>> v(n,vector<char>(m));
    vector<vector<char>> path(n,vector<char>(m));
    parent.resize(n,vector<pi>(m));
    vector<vector<int>> vis(n,vector<int>(m,0));
    int sa=-1,sb=-1,ea=-1,eb=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            v[i][j]=ch;
            if(ch=='A'){
                sa=i;
                sb=j;
            }
            if(ch=='B'){
                ea=i;
                eb=j;
            }
        }
    }
    if(eb==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    bfs(sa,sb,ea,eb,v,vis,path);
    if(ans==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    vector<char> temp;
    int r=ea,c=eb;
    while(!(r==sa&&c==sb)){
        char ch=path[r][c];
        temp.push_back(ch);
        auto p=parent[r][c];
        r=p.first;
        c=p.second;
    }
    reverse(temp.begin(),temp.end());
    cout<<"YES"<<endl;
    cout<<ans<<endl;
    for(char &x:temp) cout<<x;
    cout<<endl;
    return 0;
}