//Minimum Number of Insertion and Deletion to convert String a to String b
#include<bits/stdc++.h>
using namespace std;

int LCS(string a,string b,int m,int n){
    if(m<=0 || n<=0){
        return 0;
    }
    else{
        if(a[m-1]==b[n-1]){
            return 1+LCS(a,b,m-1,n-1);
        }else{
            return max(LCS(a,b,m-1,n),LCS(a,b,m,n-1));
        }
    }
}

void ad25(string a,string b,int m,int n){
    int ins;
    int del;
    int lcs=LCS(a,b,m,n);
    ins=n-lcs;
    del=m-lcs;
    cout<<del<<" "<<ins;
}

int main()
{
    string a="heap";
    string b="pea";
    ad25(a,b,a.length(),b.length());

}