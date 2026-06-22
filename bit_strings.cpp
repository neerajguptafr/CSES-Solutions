#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    ll b;cin>>b;
    ll res=1;
    ll a=2;
    int mod=1e9+7;
    while(b){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    cout<<res<<endl;
    return 0;
}