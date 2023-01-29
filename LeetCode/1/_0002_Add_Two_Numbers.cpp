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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode(0);
        ListNode *curr=ans;
        int c=0;
        while(l1 != NULL || l2 != NULL || c!=0){
            int a=l1 ? l1-> val : 0;
            int b=l2 ? l2->val : 0;
            int s=a+b+c;
            c = s/10;
            ListNode *t = new ListNode(s%10);
            curr->next=t;
            curr=curr->next;
            l1=l1 ? l1->next : nullptr;
            l2=l2 ? l2->next : nullptr;
        }
        return ans->next;
    }
};