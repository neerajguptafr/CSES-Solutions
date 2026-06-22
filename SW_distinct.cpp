#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int &x:v) cin>>x;
    unordered_map<int,int> mp;
    mp.reserve(n);
    mp.max_load_factor(0.25);
    int sz=0;
    for(int i=0;i<k;i++){
        if(mp[v[i]]++==0) sz++;
    }
    cout<<sz<<" ";
    for(int i=k;i<n;i++){
        int rem=v[i-k];
        if(--mp[rem]==0){
            sz--;
            mp.erase(rem);
        }
        if(++mp[v[i]]==1) sz++;
        cout<<sz<<" ";
    }
    cout<<endl;
    return 0;
}