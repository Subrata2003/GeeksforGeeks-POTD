//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {

  public:

    long long countPairs(int n, int arr[], int k) {

        vector<int> rem(k,0);

        sort(arr,arr+n);

        

        long long ans=0;

        

        for(int i=0;i<n;i++)

        {

            int ele=arr[i];

            int r=ele%k;

            

            ans+=rem[r];

            rem[r]++;

        }

        return ans;

    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends