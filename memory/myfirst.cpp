#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cout << "Enter the size of process size array and block size array" << endl;
    cin >> n >> m;

    int a[n], b[m];
    cout << "Enter the values of process size array" << endl;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }

    cout << "Enter the values of block size array" << endl;
    for(int i = 0;i<m;i++){
        cin >> b[i];
    }

    for(int i = 0;i<n;i++){
        int x = a[i];
        bool flag = false;
        for(int j = 0;j<m;j++){
            if(b[j]>=x){
                flag = true;
                cout << i+1 << "\t" << j+1<<"\t" << b[j] << endl;
                b[j]-=a[i];
                break;
            }
        }
        if(!flag) cout << i+1 << "\t no memery block found" << endl;
    }
}