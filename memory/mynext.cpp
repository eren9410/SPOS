#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int j=0;
    for(int i=0;i<n;i++){
        int x=a[i];
        bool flag =false;
        for(;j<m;j++){
            if(b[j]>=x){
                flag=true;
                cout<<i+1<<" "<<j+1<<" "<<b[j]<<endl;
                b[j]-=a[i];
                break;
            }
        }
        if(!flag) cout<<i+1<<" "<<"not memor block found"<<endl;
    }
}