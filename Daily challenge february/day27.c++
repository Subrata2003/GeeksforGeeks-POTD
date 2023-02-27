//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution

{

public:

    void rvs(vector<int> &v, int k) {

        int s=0;

        int e=k-1;

        while(s <= e) {

            swap(v[s++],v[e--]);

        }

        s=k; e=v.size()-1;

        while(s <= e) {

            swap(v[s++],v[e--]);

        }

    }

    Node* solve(Node* head, int k) {

        Node* prev = NULL;

        Node* curr = head;

        Node* start = head;

        

        while(k--) {

            Node* temp = curr->next;

            curr->next = prev;

            prev = curr;

            curr = temp;

        }

        head = prev;

        prev = NULL;

        while(curr != NULL) {

            Node* temp = curr->next;

            curr->next = prev;

            prev = curr;

            curr = temp;

        }

        start->next = prev;

        return head;

    }

    Node *reverse(Node *head, int k)

    {

        // approach 1st solve using extra space 

        // time complexity is O(n) && space complexity is O(n)

        vector<int> v;

        Node* temp = head;

        while(temp != NULL) {

            v.push_back(temp->data);

            temp = temp->next;

        }

        rvs(v,k);

        temp = head;

        for(auto ele:v) {

            temp->data = ele;

            temp = temp->next;

        }

        return head;

        

        

        // solve without using extra space

        // time complexity is O(n) && space complexity is O(1)

        Node* ans = solve(head,k);

        return ans;

    }

};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends