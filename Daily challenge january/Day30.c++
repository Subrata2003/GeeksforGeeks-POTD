//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<int> g[100000];
    vector<vector<int>> dp;
    void f(int x = 0,int par = 0){
        dp[x][1] = 1;
        for(auto it : g[x]) if(it != par){
            f(it,x);
            dp[x][1] += min(dp[it][0],dp[it][1]);
            dp[x][0] += dp[it][1];
        }
    }
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        for(auto i : edges){
            g[i[0]-1].push_back(i[1]-1);
            g[i[1]-1].push_back(i[0]-1);
        }
        dp = vector<vector<int>> (N,vector<int> (2,0));
        f();
        return min(dp[0][0],dp[0][1]);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends