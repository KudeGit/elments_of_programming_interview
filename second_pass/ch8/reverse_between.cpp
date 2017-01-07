#include <iostream>
#include <tuple>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ostream& operator<< (ostream& out, const ListNode* x) {
    if(x) {
        out << x->val;
    } else {
        out << "nullptr";
    }
    return out;
}

class Solution {
    tuple<ListNode*, ListNode*, ListNode*> reverse(ListNode*& head, int mn) {
        if (!head || mn <= 1) {
            return {head, head, head};
        }
        ListNode* prev = nullptr;
        ListNode* curr= head;
        ListNode* next = nullptr;
        cout << mn << endl;
        
        while (mn >= 0 && curr) {
            cout << curr << ",";
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next ;
            --mn;
        }
        return {prev, head, next};
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        
        if (n <= m || !head) {
            return head;
        }
        auto mm = m;
        ListNode* prev_x = nullptr;
        ListNode* x = head;
        while(mm > 1 && x) {
            prev_x = x;
            x = x->next;
            --mm;
        }
        
        if (!x) {
            return head;
        }
        
        auto head_tail_next = reverse(x, n-m);
        auto r_head = get<0>(head_tail_next);
        auto r_tail = get<1>(head_tail_next);
        auto post_r_tail = get<2>(head_tail_next);
        r_tail->next = post_r_tail;
        if (!prev_x) {
            return r_head;
        }
        prev_x->next = r_head;
        return head;
        
    }
};


int main (void)
{
    return 0;
}
