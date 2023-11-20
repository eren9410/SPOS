#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter total no. of processes " << endl;
    cin >> n;
    vector<vector<int> > v;
    int minm = INT_MAX;
    cout << "Enter burst time and arrival time of the processes" << endl;
    for(int i = 0;i<n;i++){
        int x, y;
        cin >> x >> y;
        vector<int> v3;
        v3.push_back(x);
        v3.push_back(y);
        v3.push_back(i);
        v.push_back(v3);
        minm = min(minm, y);
    }

    vector<vector<int> > v2 = v;
    int a[n];
    for(int i = 0;i<n;i++){
        a[i]=0;
    }
    set<vector<int> > s;
    int x = minm;
    while(1){
        x++;
        for(int i = 0;i<n;i++){
            if(v[i][0]!=-1 and v[i][1]<=x){
                s.insert(v[i]);
                v[i][0]=-1;
            }
        }
        for(auto x1:s){
            vector<int> v1=x1;
            v1[0]--;
            s.erase(x1);
            if(v1[0]<=0){
                a[v1[2]]=x;
            } else{
                s.insert(v1);
            }
            break;
        }
        int k = 0;
        for(int i = 0;i<n;i++){
            if(v[i][0]==-1){
                k++;
            }
        }
        if(k==v.size() and s.size()==0) break;
    }
    cout << "processes  arrival  burst  completion  waiting  tat" << endl;
    for(int i = 0;i<n;i++){
        cout << i+1 << "\t\t\t" << v2[i][1] << "\t\t\t" << v2[i][0] << "\t\t\t" << a[i] << "\t\t" << a[i]-v2[i][0]-v2[i][1] << "\t\t" << a[i]-v2[i][1] << endl;
    }
}