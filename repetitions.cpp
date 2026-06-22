#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int cnt=1;
    int sz=1;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            sz++;
            cnt=max(cnt,sz);
        }else{
            sz=1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}