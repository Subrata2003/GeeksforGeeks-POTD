//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
  string caseSort(string str, int n)

    {

        string up,lo;

        for(int i=0;i<n;i++)

        {

            if(str[i]>='A' and str[i]<='Z')

            up+=str[i];

            else 

            lo+=str[i];

        }

        

        int j=0,k=0;

        sort(lo.begin(),lo.end());

        

        sort(up.begin(),up.end());

        

        string s;

        

        for(int i=0;i<n;i++)

        {

                if(str[i]>='A' and str[i]<='Z')

                s+=up[k],k++;

                else 

                s+=lo[j],j++;

        }

        return s;
 

    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends