//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
 int minCost(vector<vector<int>> &costs) {

        // write your code here

        int n=costs.size();

        int k=costs[0].size();

        

        if(k==1 && n!=1) return -1;

 

        vector<vector<int>> dp(n,vector<int>(k,-1));

        for(int i=0;i<k;i++) dp[0][i]=costs[0][i];

        

        for(int i=1;i<n;i++){

            int mincost=INT_MAX;

            int minidx=-1;

// Finding min element and its index till wall[i]

            for(int j=0;j<k;j++){

                if(dp[i-1][j]<mincost){

                    mincost=dp[i-1][j];

                    minidx=j;

                }

            }

// Finding 2nd least element which helps in computing the

// min element for wall [i] incase the index is minidx

            int mincost2=INT_MAX;

            for(int j=0;j<k;j++){

                if(j!=minidx && dp[i-1][j]<mincost2){

                    mincost2=dp[i-1][j];

                }

            }

            

            for(int j=0;j<k;j++){

                if(j==minidx){

                    dp[i][j]=mincost2+costs[i][j];

                }

                else{

                    dp[i][j]=mincost+costs[i][j];

                }

            }

        }

        

        int ans=INT_MAX;

        for(int i=0;i<k;i++) ans=min(ans,dp[n-1][i]);

        

        return ans;

    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends