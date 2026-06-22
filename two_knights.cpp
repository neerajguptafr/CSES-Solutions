#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    int n;cin>>n;
    if(n==1){
        cout<<0<<endl;
    }else if(n==2){
        cout<<0<<endl;
        cout<<6<<endl;
    }else if(n>=2){
        cout<<0<<endl;
        cout<<6<<endl;
        for(int i=3;i<=n;i++){
            cout<<1LL*i*i*(i*i-1)/2-4LL*(i-1)*(i-2)<<endl;
        }
    }
    return 0;
}