#include<bits/stdc++.h>
using namespace std;

int LPS(string a){
    string b=a;
    int del;
    int n=a.length();
    reverse(b.begin(),b.end());
    int dp[n+1][n+1];
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
        dp[0][i]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    del=n-dp[n][n];
    return del;
}

int main(){
    string a="agbcba";
    cout<<LPS(a);
}