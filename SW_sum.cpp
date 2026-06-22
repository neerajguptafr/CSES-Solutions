#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    int n,k;cin>>n>>k;
    int x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<ll> v(n);
    v[0]=x;
    for(int i=1;i<n;i++){
        v[i]=(a*v[i-1]+b)%c;
    }
    ll sum=v[0];
    for(int i=1;i<k;i++){
        sum+=v[i];
    }
    ll xr=sum;
    for(int i=0;i+k<n;i++){
        sum+=v[i+k];
        sum-=v[i];
        xr^=sum;
    }
    cout<<xr<<endl;
    return 0;
}