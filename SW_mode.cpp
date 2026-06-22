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
    set<pi> st;
    auto add=[&](int x){
        if(mp[x]>0){
            st.erase({-mp[x],x});
        }
        mp[x]++;
        st.insert({-mp[x],x});
    };
    auto remove=[&](int x){
        int f=mp[x];
        st.erase({-f,x});
        mp[x]--;
        if(mp[x]>0){
            st.insert({-(f-1),x});
        }
    };
    for(int i=0;i<k;i++){
        add(v[i]);
    }
    cout<<st.begin()->second<<" ";
    for(int i=k;i<n;i++){
        remove(v[i-k]);
        add(v[i]);
        cout<<st.begin()->second<<" ";
    }
    cout<<endl;
    return 0;
}