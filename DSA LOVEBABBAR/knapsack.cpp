#include<bits/stdc++.h>
using namespace std;

// int knapsack(int W,int wt[],int val[],int n){
//     if(n==0 || W==0){
//         return 0;
//     }
//     if(wt[n-1]<=W){
//         return max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1));
//     }
//     else{
//         return knapsack(W,wt,val,n-1);
//     }
// }


int knapSack(int W,int wt[],int val[],int n){
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<W+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n=3;
    int wt[]={4,5,1};
    int val[]={1,2,3};
    int W=4;
    // for(int i=0;i<n;i++){
    //     cin>>wt[i];
    // }
    // for(int i=0;i<n;i++){
    //     cin>>val[i];
    // }
    // cin>>W;
    cout<<knapSack(W,wt,val,n);
    return 0;
}