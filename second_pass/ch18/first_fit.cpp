#include <iostream>
#include <vector>
#include <cassert>
#include "../../utils.hpp"



struct Box {
    double available_capacity = 1.0;
    std::vector<int> items;
};
std::ostream& operator<< (std::ostream& out, const Box& b)
{
    out << "{" << b.available_capacity << ", ("  << b.items << ")" << "}\n";
    return out;
}


void insert (const int id, const double item_capacity,
            std::vector<Box>& boxes, int i)
{
    auto left = (i << 1) + 1;
    auto right = (i << 1) + 2;
    if (left < boxes.size()) {
        insert(id, item_capacity, boxes,
                boxes[left].available_capacity >= item_capacity ? left : right);
        boxes[i].available_capacity = std::max(boxes[left].available_capacity, 
                boxes[right].available_capacity);
    } else { //leaf node
        assert(boxes[i].available_capacity >= item_capacity);
        boxes[i].available_capacity -= item_capacity;
        boxes[i].items.emplace_back(id);
    }
}

auto build_tournament_tree (const std::vector<double>& items)
{
    std::vector<Box> boxes((items.size() << 1) - 1);  //2*n - 1 nodes
    for (int i = 0; i < items.size(); ++i) {
        debug(std::make_pair(i, items[i]));
        insert(i, items[i], boxes, 0);
        debug(boxes);
    }
    return boxes;
}


int main (void)
{
    std::vector<double> items{0.6, 0.6, 0.55, 0.8, 0.5, 0.45};
    auto res = build_tournament_tree(items);
    std::cout << res << std::endl;

    return 0;
}
