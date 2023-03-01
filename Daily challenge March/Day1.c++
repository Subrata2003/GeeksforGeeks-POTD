//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        //C++ code

vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            int c[N+1][18];
            for(int i=0;i<=N;i++){
                for(int j=0;j<18;j++)c[i][j]=0;
            }
            for(auto k : U){
                int l=k[0],r=k[1],x=k[2];
                l--;
                r--;
                for(int i=0;i<18;i++){
                    if( x & 1<<i){
                        c[l][i]+=1;
                        c[r+1][i]-=1;
                    }
                }
            }
            for(int i=1;i<N;i++){
                for(int j=0;j<18;j++){
                    c[i][j] += c[i-1][j];
                }
            }
            vector<int>ans;
            for(int i=0;i<N;i++){
                int h=0;
                for(int j=0;j<18;j++){
                    if(c[i][j])h |= (1<<j);
                }
                ans.push_back(h);
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends