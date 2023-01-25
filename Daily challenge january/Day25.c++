//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
       int ans=INT_MAX,n,f;
       n=s.length();
       for(int i=0;i<n/2;i++)
       {
           f=1;
           for(int j=i+1;j<=2*i+1;j++)
           {
               if(s[j]!=s[j-i-1])
               {
                   f=0;break;
               }
           }
           if(f==1) ans=min(ans,n-i);
       }
        return min(ans,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends