#include <iostream>
#include "list.hpp"
#include "../utils.hpp"



int main (void)
{
    auto l = create_and_populate_list<int>(0, 15);
    create_loop(l, 8);
    auto ln = find_loop(l);
    debug(*ln);

    return 0;
}
