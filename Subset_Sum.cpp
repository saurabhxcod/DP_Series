#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>arr,int target){
    int n=arr.size();
    vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }

    //Iteration
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;
    if (isSubsetSum(arr, target))
    {
        cout << "Subsets with sum " << target << " exists" << endl;
    }
    else
    {
        cout << "No Subsets with sum " << target << " exists" << endl;
    }
}