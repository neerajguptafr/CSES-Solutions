#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    ll n;cin>>n;
    ll res=0;
    for(ll i=5;i<=n;i*=5){
        res+=(n/i);
    }
    cout<<res<<endl;
    return 0;
}