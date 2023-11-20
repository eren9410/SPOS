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
    vector<pair<int,int>>v;
    for(int i=0;i<m;i++){
        cin>>b[i];
        v.push_back({b[i],i+1});
    }
    
    for(int i=0;i<n;i++){
        int x=a[i];
        bool flag =false;
        sort(v.begin(),v.end());
        for(int j=m-1;j>=0;j--){
            if(v[j].first>=x){
                flag=true;
                cout<<i+1<<" "<<v[j].second<<" "<<v[j].first<<endl;
                (v[j].first)-=a[i];
                break;
            }
        }
        if(!flag) cout<<i+1<<" "<<"not memor block found"<<endl;
    }
}