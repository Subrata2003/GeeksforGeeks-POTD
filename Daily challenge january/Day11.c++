//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   long long int minIncrements(vector<int> brr, int N) {

        // Code here

        long long int ans=0;

         vector<int>arr;

        unordered_map<int,int>mp;

        for(int i=0;i<N;i++){

             mp[brr[i]]++;

            

        }

       

        for(auto it:mp){

            int k=it.second;

           while(k>1){

                arr.push_back(it.first);

                k--;

            }

        }

        if(arr.size()==0){

            return ans;

        }

        else{

             for(int i=0;i<arr.size();i++){

                 int m=arr[i];

                 while(1){

                    

                     if(mp.find(m)!=mp.end()){

                         ans++;

                         m++;   

                     }

                         else{

                          mp[m]++;

                         break;

                         

                         }

                 }

             }

        }

        return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends