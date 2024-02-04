//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
      Node* subLinkedList(Node* head1, Node* head2) {
        
        Node * helper = new Node(0);
        
        while(head1 && head1->data==0)  head1 = head1->next;
        while(head2 && head2->data==0)  head2 = head2->next;
        
        if(!head1) return head2 ? head2 : helper;
        if(!head2) return head1 ? head1 : helper;
        
        Node* t1 = head1, *t2 = head2;
        while(t1 && t2 && t1->data==t2->data){
            t1 = t1->next;
            t2 = t2->next;
        }
        
        bool one = true;
        
        if(!t1 or (t2 && t2->data>t1->data)) one = false;
        
        
        int cnt1 = 0, cnt2 = 0;
        
        t1 = head1;
        Node * next, *prev = NULL;
        
        while(t1){
            next = t1->next;
            t1->next = prev;
            prev = t1;
            t1 = next;
            ++cnt1;
        }
        
        head1 = prev;
        
        prev = NULL, t2 = head2;
        
        while(t2){
            next = t2->next;
            t2->next = prev;
            prev = t2;
            t2 = next;
            ++cnt2;
        }
        
        head2 = prev;
        
        if(one && cnt2>cnt1) one = false;
        else if(!one && cnt1>cnt2) one = true;
        
        if(!one) swap(head1,head2);
        
        Node* head = new Node(-1);
        
        Node* t = head;
        t1 = head1;
        t2 = head2;
        int sub = 0;
        
        while(t1){
            
            int num = t1->data;
            if(t2) num -= t2->data;
            num -= sub;
            
            if(num<0){
                num += 10;
                sub = 1;
            }
            else {
                sub = 0;
            }
        
            t->next = new Node(num);
            t = t->next;
            t1 = t1->next;
            if(t2) t2 = t2->next;
            
        }
        
        
        head = head->next;
        prev = NULL;
        t = head;
        
        while(t){
            next = t->next;
            t->next = prev;
            prev = t;
            t = next;
        }
        
        
        head = prev;
        
        while(head && head->data==0) head = head->next;
        
        return head ? head : helper;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends