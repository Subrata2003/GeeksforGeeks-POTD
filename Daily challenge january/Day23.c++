//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string removePair(string s) {
        // code here
int i=0,j=1;
while(j<s.size() && s.size()>1)
{
    if(s[i] == s[j]) 
    {
        s.erase(i,2);
        i=0; j=1;
    }
    else {i++;j++;}
}
if(s == "") return "-1";
else return s;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends