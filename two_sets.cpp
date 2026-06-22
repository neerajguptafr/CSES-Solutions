#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    int n;cin>>n;
    if(n==1||n==2||!(n%4==0||n%4==3)){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        if(n%4==0){
            cout<<n/2<<endl;
            for(int i=1;i<=n;i+=4){
                cout<<i<<" "<<i+3<<" ";
            }
            cout<<endl;
            cout<<n/2<<endl;
            for(int i=1;i<=n;i+=4){
                cout<<i+1<<" "<<i+2<<" ";
            }
            cout<<endl;
        }else if(n%4==3){
            cout<<n/2+1<<endl;
            cout<<1<<" "<<2<<" ";
            for(int i=4;i<=n;i+=4){
                cout<<i<<" "<<i+3<<" ";
            }
            cout<<endl;
            cout<<n/2<<endl;
            cout<<3<<" ";
            for(int i=4;i<=n;i+=4){
                cout<<i+1<<" "<<i+2<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}