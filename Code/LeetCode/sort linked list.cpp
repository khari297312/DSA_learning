#include<bits/stdc++.h>
using namespace std;
using u = unsigned;
using ll = long long;
using ull = unsigned long long;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 void PrintList(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout << temp->val << ' ';
        temp = temp->next;
    }
    cout << endl;
}

ListNode* MergeList(ListNode* h1, ListNode* h2){
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (h1 != NULL && h2 != NULL) {
        if (h1->val <= h2->val) {
            tail->next = h1;
            h1 = h1->next;
        } else {
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
    }

    if (h1 != NULL) {
        tail->next = h1;
    } else {
        tail->next = h2;
    }

    return dummy.next;
}

ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL) {
        prev->next = NULL;  // Splitting the list into two halves
    }
    return slow;
}

ListNode* MergeSort(ListNode* head){
    // Base case
    if (head == NULL || head->next == NULL){
        return head;
    }

    // Recursion
    ListNode* mid = findMid(head);
    ListNode* left = MergeSort(head);
    ListNode* right = MergeSort(mid);
    return MergeList(left, right);
}

ListNode* sortList(ListNode* head) {
    return MergeSort(head);
}

// Driver code to test the sorting function
int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original List: ";
    PrintList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    PrintList(head);

    // Free allocated memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}