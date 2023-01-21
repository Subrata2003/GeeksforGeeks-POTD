//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
       int minVal(int a, int b) {
        int cntInB = 0;
        while(b){
            if(b % 2){
                cntInB++;
            }
            b /= 2;
        }
        int ans = 0;
        for(int i = 30;(i >= 0 && cntInB > 0); i--){
            if((1 << i) & a){
                ans += (1 << i);
                cntInB--;
            }
        }
        int i = 0;
        while(cntInB){
            if(((1 << i) & a) == 0){
                ans += (1 << i);
                cntInB--;
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends