//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        for(int p=N-2;p>=0;p--){
            //if i select pink in the second last wall color
            //then oviously i selected the minimumminimum of black and yellow in the  last wall color
            colors[p][0]+=min(colors[p+1][1],colors[p+1][2]);
            
            
            //if i select black in the second last wall color
            //then oviously i selected the minimumminimum of pink and yellow in the  last wall color
            colors[p][1]+=min(colors[p+1][0],colors[p+1][2]);
            
            
            //if i select yellow in the second last wall color
            //then oviously i selected the minimumminimum of black and pink in the  last wall color
            colors[p][2]+=min(colors[p+1][1],colors[p+1][0]);
            
        }
        return min({colors[0][0],colors[0][1],colors[0][2]});
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends