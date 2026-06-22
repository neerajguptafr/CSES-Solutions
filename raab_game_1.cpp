#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    int t;cin>>t;
    while(t--){
        int n,a,b;cin>>n>>a>>b;
        if(((a==0&&b!=0)||(b==0&&a!=0))||a+b>n){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        int rem=n-(a+b);
        vector<int> v1,v2;
        while(rem--){
            v1.push_back(n);
            v2.push_back(n);
            n--;
        }
        for(int i=1;i<=n;i++) v1.push_back(i);
        for(int i=a+1;i<=n;i++) v2.push_back(i);
        for(int i=1;i<=a;i++) v2.push_back(i);
        for(int &x:v1) cout<<x<<" ";
        cout<<endl;
        for(int &x:v2) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}