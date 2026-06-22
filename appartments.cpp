#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> da(n);
    vector<int> a(m);
    for(int &x:da) cin>>x;
    for(int &x:a) cin>>x;
    sort(da.begin(),da.end());
    sort(a.begin(),a.end());
    int cnt=0;
    int i=0,j=0;
    while(i<n&&j<m){
        int x=da[i];
        int y=a[j]-k;
        ll z=a[j]+k;
        if(x>=y&&x<=z){
            cnt++;
            i++;
            j++;
        }else if(x<y){
            i++;
        }else{
            j++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}