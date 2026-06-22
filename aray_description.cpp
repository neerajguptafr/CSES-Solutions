#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;

    vector<int> v(n);
    for(int &x:v) cin>>x;
    vector<vector<int>> dp(n,vector<int>(m+2,0));
    ll res=0,cur=0;
    if(v[0]==0){
        for(int i=1;i<=m;i++) dp[0][i]=1;
    }else{
        dp[0][v[0]]=1;
    }
    for(int i=1;i<n;i++){
        cur=0;
        if(v[i]==0){
            for(int x=1;x<=m;x++){
                cur=0;
                cur=1LL*dp[i-1][x]+dp[i-1][x-1]+dp[i-1][x+1];
                dp[i][x]=(cur)%mod;
            }
        }else{
            int x=v[i];
            cur=(1LL*dp[i-1][x-1]+dp[i-1][x]+dp[i-1][x+1])%mod;
            dp[i][x]=cur;
        }
    }
    if(v.back()==0){
        for(int i=1;i<=m;i++){
            res=(res+dp[n-1][i])%mod;
        }
    }else res=dp[n-1][v.back()];
    cout<<res%mod<<endl;
    return 0;
}