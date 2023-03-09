//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
   vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        vector<Node*>ans;
        unordered_map<char,int>mp;
        for(auto x:s){
            mp[x]++;
        }
        Node*temp=head;
        unordered_map<char,int>sol=mp;
      
        while(temp){
            Node*curr=temp;
            Node*next=NULL;
            while(curr){
               
                if(sol.find(curr->data)!=sol.end()){
                    sol[curr->data]--;
                    if(sol[curr->data]==0)sol.erase(curr->data);
                    if(sol.size()==0){
                         next=curr->next;
                        curr->next=NULL;
                    
                        ans.push_back(temp);
                        
                    }
                    if(sol.size()==0)break;
                   curr=curr->next;
                    
                }
                else {
                    break;
                }
            }
            if(sol.size()==0){
                temp=next;
            }
            else {
                temp=temp->next;
            }
            
            sol=mp;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends