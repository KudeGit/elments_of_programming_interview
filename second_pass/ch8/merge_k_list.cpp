#include <iostream>
#include <vector>


using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool operator< (const ListNode& a, const ListNode& b)
{
    return a.val < b.val;
}

class Solution {
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        auto cmp = [](const qn& a, const qn& b) {
            return  a.val > b.val;
        };
        priority_queue<qn, std::vector<qn>, decltype(cmp)> Q(cmp);
        auto i = 0;
        for (int i = 0; i <lists.size(); ++i) {
            if (lists[i]) {
                Q.push(qn{lists[i], lists[i]->val});
            }
        }

        if (Q.empty()) {
            return nullptr;
        }


        ListNode *head = nullptr;
        ListNode *curr = nullptr;
        auto x = Q.top(); Q.pop();
        curr = x.x;
        head = curr;
        if (x.x->next) {
            Q.push(qn{x.x->next, x.x->next->val});
        }

        while(!Q.empty()) {
            x = Q.top(); Q.pop();
            if(x.x->next) {
                Q.push(qn{x.x->next, x.x->next->val});
            }
            curr->next = x.x;
            curr = curr->next;
        }
        return head;
    }
};


int main (void)
{
    return 0;
}
