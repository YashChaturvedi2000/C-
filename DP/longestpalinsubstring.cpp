#include<bits/stdc++.h>
using namespace std;

string LPS(string a){
    int n=a.size();
    string b=a;

    int leni=1,lenj=1;
    reverse(a.begin(),a.end());
    int dp[n+1][n+1];
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<n+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=i;j<n+1;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=0;
            }
        }
    }
}

int main()
{
    string a="babad";
    string res=LPS(a);
    cout<<res;
}