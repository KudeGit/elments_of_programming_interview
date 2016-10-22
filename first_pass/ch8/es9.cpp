#include <iostream>
#include "list.hpp"
#include "../utils.hpp"

// k = 0: remove last;
// k = 1: remove previous to last;
// ...
template <class T>
void remove_k_from_last (List<T>& l, int k)
{
    if (k < 0) {
        return;
    }
    auto x = l.head;
    auto y = x;
    //position y;
    while (y && k >= 0) {
        y = y->next;
        --k;
    }
    if (!y) {
        return;
    }
    while (y->next) {
        x = x->next;
        y = y->next;
    }
    auto a = x->next;
    debug(a.use_count());
    //remove x->next;
    x->next = x->next->next;
    debug(a.use_count());
    return;
}


int main (void)
{
    auto l = create_and_populate_list<int>(0, 15);
    std::cout << l << std::endl;
    remove_k_from_last(l, 3);
    std::cout << l << std::endl;
    return 0;
}

