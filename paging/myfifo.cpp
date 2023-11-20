#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, f;
    cout << "Enter the total no. of pages" << endl;
    cin >> n;
    cout << "Enter the frame size" << endl;
    cin >> f;

    vector<int> v(n);
    cout << "Enter the page numbers " << endl;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    vector<int> x;
    int a = 0,j=0;
    for(int i = 0;i<n;i++){
        if(x.size()<f){
            if(find(x.begin(), x.end(), v[i])==x.end()){
                x.push_back(v[i]);
                a++;
            }
        } else{
            if(find(x.begin(),x.end(), v[i])==x.end()){
                x[j]=v[i];
                a++;
                j=(j+1)%f;
            }
        }

        for(int k = 0;k<x.size();k++){
            cout << x[k] << " ";
        }
        cout << endl;
    }
    cout << "Total no. of page faults is " << a << endl;
}