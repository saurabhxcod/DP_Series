#include <iostream>
#include<vector>
using namespace std;
int knapsack(int n,int W,vector<int>val,vector<int>wt){
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][W-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main(){
    int n=4,W=8;
    vector<int>wt={3,4,5,6};
    vector<int>val={2,3,4,5};
    cout<<"Maximum profit:  "<<knapsack(n,W,val,wt)<<endl;
    return 0;
}