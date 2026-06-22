#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<vector<char>> v(n,vector<char>(n));
    for(auto &x:v){
        for(auto &y:x){
            cin>>y;
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    if(v[0][0]=='*'){
        cout<<'0'<<endl;
        return 0;
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0) continue;
            if(v[i][j]=='.'){
                int up=0,le=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) le=dp[i][j-1];
                ll x=(up+le)%mod;
                dp[i][j]=x;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}