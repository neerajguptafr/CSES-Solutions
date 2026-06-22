#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
void solve(int sum,vector<int> &v){
    int n=v.size();
    sort(v.begin(),v.end());
    vector<int> dp(sum+1,1e9);
    for(int &x:v){
        if(x<=sum) dp[x]=1;
    }
    for(int i=1;i<=sum;i++){
        for(int &x:v){
            if(i-x>0) dp[i]=min(dp[i],dp[i-x]+1);
        }
    }
    if(dp[sum]==1e9) cout<<-1<<endl;
    else cout<<dp[sum]<<endl;
}
int main(){
    int n;cin>>n;
    int sum;cin>>sum;
    vector<int> v(n);
    for(int &x:v) cin>>x;
    solve(sum,v);
    return 0;
}