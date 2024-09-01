#include <bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
   ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 void print(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<' ';
        head=head->next;
    }
    cout<<endl;
}
class Solution {
public:
    ListNode* reverseBetween(ListNode* &head, int left, int right) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        int k=left;
        while(--k){
            prev=curr;
            curr=curr->next;
        }
        ListNode* leftNode=prev;
        ListNode* temp=curr->next;
        k=right-left;
        while(k>=0){
            curr->next=prev;
            prev=curr;
            curr=temp;
            if(temp==NULL) break;
            temp=temp->next;
        k--;
        }
        ListNode* rightPrev;
        if(leftNode==NULL){rightPrev=head;head=prev;}
        else{rightPrev=leftNode->next;}

        rightPrev->next=curr;
        if(leftNode!=NULL){leftNode->next=prev;}
        return head;
    }
};

int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    head->next->next->next->next->next=new ListNode(6);
    head->next->next->next->next->next->next=new ListNode(7);
    print(head);
    Solution s;
    s.reverseBetween(head,1,7);
    print(head);
    return 0;
}