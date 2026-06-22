#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;cin>>n>>k;
    int x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<ll> v(n);
    v[0]=x;
    for(int i=1;i<n;i++){
        v[i]=(a*v[i-1]+b)%c;
    }
    int xr=0;
    for(int i=0;i<k;i++){
        xr^=v[i];
    }
    int res=xr;
    for(int i=0;i+k<n;i++){
        xr^=v[i];
        xr^=v[i+k];
        res^=xr;
    }
    cout<<res<<endl;
    return 0;
}