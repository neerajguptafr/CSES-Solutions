#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    for(auto &ch:s) mp[ch]++;
    int cnt=0;
    for(auto &p:mp){
        char x=p.first;
        int c=p.second;
        if(c%2) cnt++;
    }
    if(cnt>1) cout<<"NO SOLUTION"<<endl;
    else{
        string res="";
        char oddch='$';
        for(auto &p:mp){
            char x=p.first;
            int c=p.second;
            if(c%2) oddch=x;
            for(int i=0;i<(c/2);i++){
                res+=x;
            }
        }
        string temp=res;
        reverse(temp.begin(),temp.end());
        if(oddch!='$') res+=oddch;
        res+=temp;
        cout<<res<<endl;
    }
    return 0;
}