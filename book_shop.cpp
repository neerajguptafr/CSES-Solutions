#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mod=1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;

    vector<int> price(n), pages(n);

    for(int &v:price) cin>>v;
    for(int &v:pages) cin>>v;
    
    vector<int> dp(x+1,0);
    for(int i=0;i<n;i++){
        for(int j=x;j>=price[i];j--){
            dp[j]=max(dp[j],
                      dp[j-price[i]]+pages[i]);
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}