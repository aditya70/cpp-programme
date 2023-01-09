  #include <bits/stdc++.h>
  using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *n1=head, *n2=head->next;
        ListNode *rev=swapPairs(head->next->next);
        n2->next=n1;
        n1->next=rev;
        head=n2;
        return head;
    }
};