//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        if(S==1 || D==1) return "-1";
         string f="";
         for(int i=0; i<D; ++i) {
             int a=0,b=0;
             if(i==0) a=1;
             for(int j=a; j<10; ++j) {
                 if((D-i-1)*9>=S-j) {
                     f.push_back(j+'0');
                     b=1;
                     S-=j;
                     break;
                 }
             }
             if(b==0) return "-1";
         }
         int nine=D-1;
         if(f[D-1]=='9') {
             for(int i=D-1; i>-1; --i) {
                 if(f[i]=='9') {
                     nine=i;
                 }
                 else break;
             }
         }
         f[nine]=f[nine]-'0'-1+'0';
         if(nine-1>=0) {
             f[nine-1]=f[nine-1]-'0'+1+'0';
         }
         else return "-1";
         return f;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends