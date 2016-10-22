#include <iostream>
#include <queue>
#include <vector>
#include "utils.hpp"
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main (void) {
    auto cmp = [](ListNode* lhs, ListNode* rhs) {
        return lhs->val < rhs->val;
    };
    std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> Q(cmp);
    if (!Q.empty()) {
        auto curr = Q.front();
    }
    return 0;
}
