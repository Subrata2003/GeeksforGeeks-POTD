//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  vector<vector<long long>>values;

  void dfs(int source, vector<int>adj[], int parent, vector<int>&A, vector<bool>&leaf)
  {
      bool isleaf=true;

      for(auto child:adj[source])
      {
          if(child!=parent)
          {
              isleaf=false;
              values[child][0]=max(values[child][0],values[source][1]+A[child]);
              values[child][1]=max(values[child][1],values[source][0]-A[child]);
              dfs(child,adj,source,A,leaf);
          }
      }

      leaf[source]=isleaf;
  }
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        // code here
        vector<int>adj[N];
        values=vector<vector<long long>>(N,vector<long long>(2,-1e18));
        //values[i][0]--+  values[i][1]--(-)
        for(int i=0;i<N; i++)P[i]--;

        for(int i=1; i<N; i++)
        {
            adj[i].push_back(P[i]);
            adj[P[i]].push_back(i);
        }

        for(int i=0;i<N; i++)
        {
            values[i][0]=A[i];
        }

        vector<bool>leaf(N,false);

        dfs(0,adj,-1, A,leaf);

        long long ans=-1e18;

        for(int i=0;i<N; i++)
        {
            if(leaf[i])
            {
                ans=max(ans,values[i][0]);
                ans=max(ans,values[i][1]);
            }
        }

        return ans;

    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends