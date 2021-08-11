#include<bits/stdc++.h>
using namespace std;

string SCS(string a,string b,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<n+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    int i=m,j=n;
    string s="";
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            s.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                s.push_back(b[j-1]);
                j--;
            }else{
                s.push_back(a[i-1]);
                i--;
            }
        }
    }

    while(i>0){
        s.push_back(a[i]);
        i--;
    }
    while(j>0){
        s.push_back(b[j]);
        j--;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    string a="acbcf";
    string b="abcdaf";
    int m=a.length();
    int n=b.length();
    cout<<SCS(a,b,m,n);
    return 0;
}