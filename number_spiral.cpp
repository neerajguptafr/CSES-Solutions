#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    int t;cin>>t;
    while(t--){
        int r,c;cin>>r>>c;
        int mx=max(r,c)-1;
        ll num;
        if(r==c){
            num=(1LL*r*r-(r-1));
        }else if(r>c){
            if(r%2){
                int x=r-1;
                num=(1LL*x*x+c);
            }else{
                num=(1LL*r*r-(c-1));
            }
        }else{
            if(c%2){
                num=(1LL*c*c-(r-1));
            }else{
                int x=c-1;
                num=(1LL*x*x+r);
            }
        }
        cout<<num<<endl;
    }
    return 0;
}