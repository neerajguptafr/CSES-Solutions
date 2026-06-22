#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
vector<int> dp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<int> dp(n+1,1e9);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int x=i;
        while(x){
            int l=x%10;
            dp[i]=min(dp[i],dp[i-l]+1);
            x/=10;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}