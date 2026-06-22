#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
    vector<int> f(vector<int>& v, int k){
        int n=v.size();
        priority_queue<int> maxheap;
        priority_queue<int,vector<int>,greater<int>> minheap;
        unordered_map<int,int> mp;
        int mins=0,maxs=0;
        vector<int> ans;
        vector<ll> pre(n,0);
        auto prunemin=[&](){
            while(!minheap.empty()&&mp[minheap.top()]>0){
                mp[minheap.top()]--;
                minheap.pop();
            }
        };
        auto prunemax=[&](){
            while(!maxheap.empty()&&mp[maxheap.top()]>0){
                mp[maxheap.top()]--;
                maxheap.pop();
            }
        };
        auto balance=[&](){
            while(maxs>mins+1){
                minheap.push(maxheap.top());
                maxheap.pop();
                mins++;
                maxs--;
                prunemax();
            }
            while(mins>maxs){
                maxheap.push(minheap.top());
                minheap.pop();
                maxs++;
                mins--;
                prunemin();
            }
        };
        auto add=[&](int x){
            if(maxheap.empty()||x<=maxheap.top()){
                maxheap.push(x);
                maxs++;
            }else{
                minheap.push(x);
                mins++;
            }
            balance();
        };
        auto remove=[&](int x){
            mp[x]++;
            if(x<=maxheap.top()){
                maxs--;
                if(x==maxheap.top()){
                    prunemax();
                }
            }else{
                mins--;
                if(!minheap.empty()&&x==minheap.top()){
                    prunemin();
                }
            }
            balance();
        };
        auto puush=[&](){
            int val;
            val=maxheap.top();
            ans.push_back(val);
        };
        for(int i=0;i<k;i++){
            int x=v[i];
            add(x);
            if(i==0){
                pre[i]=v[i];
            }else{
                pre[i]=pre[i-1]+v[i];
            }
        }
        puush();
        for(int i=k;i<n;i++){
            add(v[i]);
            remove(v[i-k]);
            puush();
        }
        return ans;
    }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int &x:v) cin>>x;
    vector<int> ans=f(v,k);
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}