//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    bool is_prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    // Function to find the nearest prime number
    int nearest_prime(int n) {
        if (is_prime(n)) return n;
        int prev = n - 1;
        int next = n + 1;
        while (!is_prime(prev) || !is_prime(next)) {
            if (is_prime(prev)) return prev;
            if (is_prime(next)) return next;
            prev--;
            next++;
        }
        return prev;
    }
    Node *primeList(Node *head) {
        Node *temp = head;
        while(temp) {
            int prime = nearest_prime(temp->val);
            temp->val = prime;
            temp = temp->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends