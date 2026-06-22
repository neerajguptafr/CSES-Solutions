#include<bits/stdc++.h>
using namespace std;
void f(int n,int src,int dst,int aux){
    if(n==0) return;
    f(n-1,src,aux,dst);
    cout<<src<<" "<<dst<<endl;
    f(n-1,aux,dst,src);
}
int main(){
    int n;cin>>n;
    cout<<(1<<n)-1<<endl;
    f(n,1,3,2);
    return 0;
}