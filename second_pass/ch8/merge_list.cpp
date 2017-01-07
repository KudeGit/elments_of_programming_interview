#include <iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


bool operator< (const ListNode& lhs, const ListNode& rhs)
{
    return lhs.val < rhs.val;
}


ostream& operator<< (ostream& out, const ListNode& x)
{
    out << x.val;
    return out;
}


ostream& operator<< (ostream& out, ListNode* x)
{
    out << (x ? x->val : 0);
    return out;
}

#define debug(x) cout << #x ":" << x << endl

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (!l1 || !l2) {
                return l1 ? l1 : l2;
            }
            ListNode* l3 = nullptr;
            ListNode* l3_head = nullptr;
            {
                auto& x = *l1 < *l2 ? l1 : l2;
                l3 = x;
                x = x->next;
                l3_head = l3;
            }


            while (l1 && l2) {
                auto& x = *l1 < *l2 ? l1 : l2;
                l3->next = x;
                l3 = l3->next;
                x = x->next;
            }

            auto& x = l1 ? l1 : l2;
            while (x) {
                l3->next = x;
                l3 = l3->next;
                x = l1->next; 
            }
            return l3_head;
        }
};



int main (void)
{
    //tested on leetcode
    return 0;
}
