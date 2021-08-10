#include<bits/stdc++.h>
using namespace std;

int LCS(string a,string b,int m,int n){
    if(m<=0 || n<=0){
        return 0;
    }
    else{
        if(a[m-1]==b[n-1]){
            return 1+LCS(a,b,m-1,n-1);
        }
        else{
            return max(LCS(a,b,m-1,n),LCS(a,b,m,n-1));
        }
    }
}

int main()
{
    string a="geek";
    string b="eke";
    cout<<LCS(a,b,a.length(),b.length());
    return 0;
}