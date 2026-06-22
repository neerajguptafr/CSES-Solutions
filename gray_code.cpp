#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int l=1<<n;
    for(int i=0;i<l;i++){
        int gray=i^(i>>1);
        for(int j=n-1;j>=0;j--){
            cout<<((gray>>j)&1);
        }
        cout<<endl;
    }
    return 0;
}