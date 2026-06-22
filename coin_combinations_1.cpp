#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,sum;cin>>n>>sum;
    vector<int> v(n);
    for(int &x:v) cin>>x;
    sort(v.begin(),v.end());
    vector<int> dp(sum+1);
    dp[0]=1;
    for(int i=1;i<=sum;i++){
        ll cur=0;
        for(int j=0;j<n&&i-v[j]>=0;j++){
            int x=v[j];
            if(i-x<0) break;
            cur+=dp[i-x];
        }
        dp[i]=(cur%mod);
    }
    cout<<dp[sum]<<endl;
    return 0;
}