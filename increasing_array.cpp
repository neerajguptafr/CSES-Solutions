#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    ll cnt=0;
    for(int i=1;i<n;i++){
        if(v[i-1]>v[i]){
            cnt+=(v[i-1]-v[i]);
            v[i]=v[i-1];
        }
    }
    cout<<cnt<<endl;
    return 0;
}