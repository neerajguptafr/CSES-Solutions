#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n;cin>>n;
    if(n==1){
        cout<<"1"<<endl;
    }else if(n==4){
        cout<<"2 4 1 3"<<endl;
    }else if(n<5) cout<<"NO SOLUTION"<<endl;
    else{
        int a=1;
        int b=n/2+1;
        if(n&1) b=n/2+2;
        while(a<=n/2){
            cout<<a++<<" ";
            cout<<b++<<" ";
        }
        if(n&1) cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}