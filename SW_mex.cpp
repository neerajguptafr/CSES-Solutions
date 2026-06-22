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
    set<int> st;
    for(int i=0;i<=k;i++) st.insert(i);
    auto add=[&](int x){
        if(++mp[x]==1){
            if(st.count(x)) st.erase(x);
        }
    };
    auto remove=[&](int x){
        if(--mp[x]==0){
            st.insert(x);
        }
    };
    for(int i=0;i<k;i++){
        add(v[i]);
    }
    cout<<*st.begin()<<" ";
    for(int i=k;i<n;i++){
        remove(v[i-k]);
        add(v[i]);
        cout<<*st.begin()<<" ";
    }
    cout<<endl;
    return 0;
}