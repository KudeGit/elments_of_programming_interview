#include <iostream>
#include "../ch10/btree.hpp"
#include <unordered_set>


template <class T>
std::shared_ptr<BTN<T>> lower_common_ancestor (
        std::shared_ptr<BTN<T>> a,
        std::shared_ptr<BTN<T>> b)
{
    if(!(a && b)) {
        return nullptr;
    }
    std::unordered_set<std::shared_ptr<BTN<T>>> parents;
    while (a && b && a != b) {
        if (parents.find(a) == parents.end()) {
            parents.insert(a);
        } else {
            return a;
        }
        if (parents.find(b) == parents.end()) {
            parents.insert(b);
        } else {
            return b;
        }

        auto pa = a->parent.lock();
        auto pb = b->parent.lock();
        a = pa;
        b = pb;
    }
    while (a) {
        if (parents.find(a) != parents.end()) {
            return a;
        }
        auto pa = a->parent.lock();
        a = pa;
    }

    while (b) {
        if (parents.find(b) != parents.end()) {
            return b;
        }
        auto pb = b->parent.lock();
        b = pb;
    }
    return nullptr;
}


int main (void)
{
    auto root = create_3_unbalanced_tree();
    auto a = find(root, 'h');
    auto b = find(root, 'b');
    auto lca = lower_common_ancestor(a, b);
    if (lca) {
        std::cout << *lca << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    return 0;

}
