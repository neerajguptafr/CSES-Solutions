#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<ll> v(n);
    v[0]=x;
    for(int i=1;i<n;i++){
        v[i]=(a*v[i-1]+b)%c;
    }
    deque<ll> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty()&&v[dq.back()]>=v[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ll xr=v[dq.front()];
    for(int i=0;i+k<n;i++){
        while(!dq.empty()&&v[dq.back()]>=v[i+k]){
            dq.pop_back();
        }
        if(!dq.empty()&&dq.front()<=i) dq.pop_front();
        dq.push_back(i+k);
        xr^=v[dq.front()];
    }
    cout<<xr<<endl;
    return 0;
}