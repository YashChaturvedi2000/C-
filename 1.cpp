#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int n=a.length();
     for (int i = 0; i < n; i++){ 
        for (int len = 1; len <= n - i; len++){
            cout << a.substr(i, len) << endl;
        }
     }
            
}