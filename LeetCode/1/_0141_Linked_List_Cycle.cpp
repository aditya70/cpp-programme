#include <bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *s_ptr=head, *f_ptr=head;
        while (s_ptr && f_ptr && f_ptr->next){
            s_ptr=s_ptr->next;
            f_ptr=f_ptr->next->next;
            if(s_ptr == f_ptr) return true;
        }
        return false;
    }
};

int main(){
    return 0;
}