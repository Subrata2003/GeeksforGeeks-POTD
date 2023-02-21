//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // If you will look at the problem carefully it is just asking to find the cell which have max distance from current cell and return the distance;
        int val = 0; // val will store the maximum distance between the given cell to any other cell in matrix;
        x--; // reducing x by 1 for zero based indexing;
        y--; // reducing y by 1 for zeron based indexing;
        for(int i= 0; i<N; i++){ // iterate the matrix;
            for(int j = 0; j<M ;j++){
                val = max(val,abs(x-i) + abs(y-j)); // val will store the max of val and distance between given cell to current cell;
            }
        }
        return val; // return the max value obtained;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends