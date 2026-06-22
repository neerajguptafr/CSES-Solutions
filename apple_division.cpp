#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int &x:v) cin>>x;
    ll total=accumulate(v.begin(),v.end(),0LL);
    ll ans=1e9;
    for(int mask=0;mask<=(1<<n);mask++){
        ll sum=0;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                sum+=v[i];
            }
        }
        ans=min(ans,abs(total-2*sum));
    }
    cout<<ans<<endl;
    return 0;
}