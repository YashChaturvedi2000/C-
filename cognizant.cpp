#include<bits/stdc++.h>
using namespace std;


int compareby(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

vector<int> solve(int input1,vector<vector<int>> &input2,int input3){
    vector<int> res;
    if(input2.size()<input1){
        res.push_back(-1);
        return res;
    }
    int first=input2[0][0];
    int last=input2[input2.size()-1][0];
    res.push_back(first);
    res.push_back(last);
    for(int j=0;j<input3-res.size();j++){
        for(int i=j+2;i<input2.size()-1;i++){
            if(input2[i-1][0]<input2[i][0]){
                res.push_back(input2[i-1][0]);
            }

        }
    }

    sort(res.begin(),res.end());
    // int arr[res.size()];
    // for(int i=0;i<res.size();i++){
    //     arr[i]=res[i];
    // }
    // return arr;
    return res;

}

int main()
{
    int input1,input3;
    cin>>input1;
    vector<vector<int>> input2;
    vector<int> ok;
    int temp;
    for(int i=0;i<input1;i++){
       for(int j=0;j<2;j++){
           cin>>temp;
           ok.push_back(temp);
       }
       input2.push_back(ok);
    }
    cin>>input3;
    vector<int> res=solve(input1,input2,input3);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
