#include <iostream>
#include "list.hpp"
#include "../utils.hpp"



int main (void)
{
    auto l1 = create_and_populate_list<int> (0, 5);
    auto l2 = create_and_populate_list<int> (0, 7);
    auto l3 = create_and_populate_list<int> (10, 15);
    auto tail1 = l1.get_tail();
    auto tail2 = l2.get_tail();
    tail1->next = l3.head;
    tail2->next = l3.head;

    auto x = overlapping_list(l1, l2);
    std::cout << *x << std::endl;
    return 0;


}
