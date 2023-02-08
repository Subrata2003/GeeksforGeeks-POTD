//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){

      //Code Here

      vector<long long int>v;

      vector<int>row(n+1,0),col(n+1,0);

      

      long long ans_row=n;

      long long ans_col=n;

      

      for(int i=0;i<k;i++)

      {

          int r=arr[i][0];

          int c=arr[i][1];

          if(!row[r] )

          {

              row[r]=1;

              ans_row--;

          }

          if(!col[c])

          {

              col[c]=1;

              ans_col--;

          }

          v.push_back(ans_row*ans_col);

      }

      

      return v;

  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends