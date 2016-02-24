#include <iostream>
#include "list.hpp"
#include "../utils.hpp"

template <class T>
void remove_duplicates (List<T>& l) 
{
    auto x = l.head;
    auto y = x;
    while (x) {
        if(y && y->data == x->data) {
            x->next = y->next;
            y = y->next;
        } else {
            x->next = y;
            x = x->next;
        }
    }
}


int main (void) 
{
    auto l = create_and_populate_list_with_duplicates<int>(0, 10, 4);
    std::cout << l << std::endl;
    remove_duplicates(l);
    std::cout << l << std::endl;
    return 0;


}
