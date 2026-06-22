#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    string s;cin>>s;
    string t=s;
    sort(t.begin(),t.end());
    string str=t;
    int k=1;
    next_permutation(t.begin(),t.end());
    while(t!=str){
        k++;
        next_permutation(t.begin(),t.end());
    }
    cout<<k<<endl;
    cout<<t<<endl;
    next_permutation(t.begin(),t.end());
    while(t!=str){
        cout<<t<<endl;
        next_permutation(t.begin(),t.end());
    }
    return 0;
}