#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter total no. of processes" << endl;
    cin >> n;
    vector<pair<pair<int, int>,int> > v;
    cout << "Enter the Arrival time and burst time of the processes" <<endl;
    for(int i = 0;i< n;i++){
        int x, y;
        cin >> x >> y;
        v.push_back({{x,y}, i});
    }
    sort(v.begin(), v.end());
    int a[n];
    for(int i = 0;i<n;i++){
        a[i]=0;
    }

    int x = v[0].first.first;
    for(int i = 0;i<n;i++){
        if(x<=v[i].first.first){
            a[v[i].second] = v[i].first.first + v[i].first.second;
            x = a[v[i].second];
        }else {
            a[v[i].second] = v[i].first.first + v[i].first.second + (abs(x-v[i].first.first));
            x = a[v[i].second];
        }
    }

    cout << "Process no.  Arrival  Burst  Completion  Tot  waitin" << endl;
    for(int i = 0;i<n;i++){
        cout << (i+1) << "\t" << v[i].first.first << "\t" << v[i].first.second << "\t" << a[i] << "\t" << a[i]-v[i].first.first << "\t" << a[i]-v[i].first.first-v[i].first.second << endl;
    }
}
