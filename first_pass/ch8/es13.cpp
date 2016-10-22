#include <iostream>
#include "list.hpp"
#include "../utils.hpp"

template <class T>
void zip(List<T>& l)
{
    auto x = l.head;
    auto y = l.head;
    auto prev_x = l.head;
    prev_x = nullptr;
    while (x && y) {
        y = y->next;
        if(y) {
            x = x->next;
            y = y->next;
            prev_x = x;
        }
    }
    if(!prev_x) {
        return;
    }
    List<T> second_half(x->next);
    second_half.reverse();
    x->next = nullptr;
    y = second_half.head;
    x = l.head;
    auto next_x = x->next;
    auto next_y = y ? y->next : y;
    while(x && y) {
        next_x = x->next;
        next_y = y->next;
        x->next = y;
        y->next = next_x;
        x = next_x;
        y = next_y;
    }
}


int main (void) 
{
    auto l = create_and_populate_list<int>(0, 13);
    std::cout << l << std::endl;
    zip(l);
    std::cout << l << std::endl;
    return 0;
}
