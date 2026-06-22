#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n;cin>>n;
    int val;
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }
    for(int i=1;i<n;i++){
        cin>>val;
        if(s.count(val)) s.erase(val);
    }
    cout<<*s.begin()<<endl;
    return 0;
}