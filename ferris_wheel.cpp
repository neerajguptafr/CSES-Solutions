#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int &x:v) cin>>x;
    sort(v.begin(),v.end());
    int cnt=0;
    int i=0,j=n-1;
    while(i<=j){
        if(v[i]+v[j]<=x){
            i++;
            j--;
        }else{
            j--;
        }
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}