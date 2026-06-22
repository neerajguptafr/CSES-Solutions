#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
vector<int> dp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,sum;cin>>n>>sum;
    vector<int> v(n);
    for(int &x:v) cin>>x;
    sort(v.begin(),v.end());
    dp.resize(sum+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=v[i];j<=sum;j++){
            ll res=(dp[j]+dp[j-v[i]])%mod;
            dp[j]=res;
        }
    }
    cout<<dp[sum]<<endl;
    return 0;
}