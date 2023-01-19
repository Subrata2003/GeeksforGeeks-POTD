//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{

    public:

    int func(int a, int b){

        int answer = 0;

        while(a > b){

            answer += 1;

            a /= 2;

        }

        return answer;

    }

    int carpetBox(int A, int B, int C, int D){

        int first = func(A, C) + func(B, D);

        int second = func(B, C) + func(A, D);

        

        return min(first, second);

    }

};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends