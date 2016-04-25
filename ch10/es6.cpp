#include <iostream>
#include "btree.hpp"
#include "../utils.hpp"


void get_root_2_leaves_paths_sum_helper(const std::shared_ptr<BTN<bool>>& root,
        size_t current, size_t& tot_sum) 
{
    if (!root) {
        return;
    }
    current = (current << 1) | (root->data ? 0x1ull : 0x0ull);
    if (!root->left && !root->right) {
        tot_sum += current;
        return;
    }
    get_root_2_leaves_paths_sum_helper(root->left, current, tot_sum);
    get_root_2_leaves_paths_sum_helper(root->right, current, tot_sum);
    return;
}

size_t get_root_2_leaves_paths_sum (const std::shared_ptr<BTN<bool>>& root) {
    size_t current = 0;
    size_t tot_sum = 0;
    get_root_2_leaves_paths_sum_helper (root, current, tot_sum);
    return tot_sum;
}


std::shared_ptr<BTN<bool>> create_bool_tree (void)
{
    auto a = std::make_shared<BTN<bool>>();
    auto b = std::make_shared<BTN<bool>>();
    auto c = std::make_shared<BTN<bool>>();
    auto d = std::make_shared<BTN<bool>>();
    auto e = std::make_shared<BTN<bool>>();
    auto f = std::make_shared<BTN<bool>>();
    auto g = std::make_shared<BTN<bool>>();
    auto h = std::make_shared<BTN<bool>>();
    auto i = std::make_shared<BTN<bool>>();
    auto j = std::make_shared<BTN<bool>>();
    auto k = std::make_shared<BTN<bool>>();
    auto l = std::make_shared<BTN<bool>>();
    auto m = std::make_shared<BTN<bool>>();
    auto n = std::make_shared<BTN<bool>>();
    auto o = std::make_shared<BTN<bool>>();
    auto p = std::make_shared<BTN<bool>>();

    a->data = e->data = f->data = g->data = i->data = l->data = m->data = true; 
    b->data = c->data = d->data = h->data = false;
    j->data = k->data = n->data = o->data = p->data = false;

    a->left = b; a->right = i;
    b->left = c; b->right = f;
    c->left = d; c->right = e;
    f->right = g;
    g->left = h;

    i->left = j; i->right = o;
    j->right = k;
    k->left = l; k->right = n;
    l->right = m;

    o->right = p;

    return a;


}

int main (void) 
{

    auto root = create_bool_tree();
    auto res = get_root_2_leaves_paths_sum(root);
    std::cout << res << std::endl;
    return 0;

}
