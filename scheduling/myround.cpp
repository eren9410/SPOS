#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,qu;cin>>n>>qu;
    vector<vector<int>>v;
    cout<<" arival"<<" "<<" burst"<<endl;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        vector<int> v1;
        v1.push_back(x);
        v1.push_back(y);
        v1.push_back(i);
        v.push_back(v1);
    }
    vector<vector<int>>v2=v;
    sort(v.begin(),v.end());
    int x=v[0][0];//timer;
    int a[n];//ct arr
    for(int i = 0;i<n;i++){a[i]=0;}
    queue<vector<int>>q;
    while(1){
        for(int i=0;i<n;i++){
            if(v[i][0]!=-1 && v[i][0]<=x){
                q.push(v[i]);
                v[i][0]=-1;
            } 
        }
        if(q.size()!=0){
            vector<int> v3=q.front();
            q.pop();
            if(v3[1]<=qu){
                x+=v3[1];
                a[v3[2]]=x;
            }
            else{
                x+=qu;
                v3[1]-=qu;
                for(int i=0;i<n;i++){
                    if(v[i][0]!=-1 && v[i][0]<=x){
                        q.push(v[i]);
                        v[i][0]=-1;
                    } 
                }
                q.push(v3);
            }
        }
        else x++;
        int k=0;
        for(int i=0;i<n;i++){
            if(v[i][0]==-1){
                k++;
            }
        }
        if(k==v.size() && q.size()==0) break;
    }
    cout<<"processno "<< " arrival "<< " brust "<<" compliton "<<" waiting time "<<" tot"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t\t\t"<<v2[i][0]<<"\t\t\t"<<v2[i][1]<<"\t\t"<<a[i]<<"\t\t"<<a[i]-((v2[i][0] + v2[i][1]))<<"\t\t\t"<<a[i]-(v2[i][0])<<endl;
    }
}
