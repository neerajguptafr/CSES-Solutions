#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;cin>>n>>k;
    int x,a,b,c;
    cin>>x>>a>>b>>c;
    int res=0;
    vector<int> v(n),pre(n),suf(n);
    for(int i=0;i<n;i++){
        v[i]=x;
        x=(1LL*a*x+b)%c;
    }
    for(int i=0;i<n;i+=k){
        pre[i]=v[i];
        int l=min(i+k,n);
        for(int j=i+1;j<l;j++){
            pre[j]=v[j]|pre[j-1];
        }
        suf[l-1]=v[l-1];
        for(int j=l-2;j>=i;j--){
            suf[j]=v[j]|suf[j+1];
        }
    }
    int num=0;
    for(int i=k-1;i<n;i++){
        num=pre[i]|suf[i-k+1];
        res^=num;
    }
    cout<<res<<endl;
    return 0;
}