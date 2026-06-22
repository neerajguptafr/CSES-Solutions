#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
void solve(int &n){
    if(n<=6){
        cout<<(1<<(n-1))<<endl;
        return;
    }
    vector<int> dp(max(n,7));
    for(int i=0;i<6;i++) dp[i]=(1<<i);
    dp[6]=63;
    for(int i=7;i<n;i++){
        dp[i]=(2LL*dp[i-1]-dp[i-7]+mod)%mod;
    }
    cout<<dp[n-1]<<endl;
    return;
}
int main(){
    int n;cin>>n;
    solve(n);
    return 0;
}