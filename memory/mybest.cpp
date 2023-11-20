#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cout << "Enter the size of process size array and block size array" << endl;
    cin >> n >> m;

    int a[n], b[m];
    vector<pair<int, int> > v;
    cout << "Enter the values of process size array" << endl;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }

    cout << "Enter the values of block size array" <<endl;
    for(int i = 0;i<m;i++){
        cin >> b[i];
        v.push_back({b[i], i+1});
    }

    for(int i = 0;i<n;i++){
        int x = a[i];
        bool flag = false;
        sort(v.begin(), v.end());
        for(int j = 0;j<m;j++){
            if(v[j].first>=x){
                flag = true;
                cout << i+1 << "\t" << v[j].second << "\t" << v[j].first <<endl;
                (v[j].first)-=a[i];
                break;
            }
        }
        if(!flag) cout << i+1 << "\t no memory block found" << endl;
    }
}