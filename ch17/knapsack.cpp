#include <iostream>
#include <vector>
#include "../utils.hpp"

struct Item {
    int v = 0;
    int w = 0;
    Item(int ww, int vv) : v(vv), w(ww) {}
    Item() : v(0), w(0) {}
    Item(const Item& other) : v(other.v), w(other.w) {}
    Item(Item&& other) : v(std::move(other.v)), w(std::move(other.w)) {}
    Item& operator= (Item i) {
        this->swap(i);
        return *this;
    }

    private:
    void swap (Item& other) {
        std::swap(this->v, other.v);
        std::swap(this->w, other.w);
    }

};



int knapsack_with_repetition (const std::vector<Item>& items, const int W)
{
    std::vector<int> K(W+1, 0);
    for (int w = 0; w <= W; ++w) {
        int max_for_this_w = 0;
        for (const auto& item: items) {
            if (item.w <= w) {
                max_for_this_w = std::max(max_for_this_w, K[w - item.w] + item.v);
            }
        }
        K[w] = max_for_this_w;
    }
    return K.back();
}

int knapsack_without_repetition (const std::vector<Item>& items, const int W)
{
    std::vector<std::vector<int>> K(W+1, std::vector<int>(items.size() + 1, 0));
    
    //fist row of K set to 0 already
    //first column of K set to 0 already

    for (int w = 0; w <= W; ++w) {
        for (int i = 0; i < items.size(); ++i) {
            auto current_item = items[i];
            if (items[i].w <= w) {
                K[w][i+1] = std::max(K[w - current_item.w][i] + current_item.v, K[w][i]);
            } else {
                K[w][i+1] = K[w][i];
            }
        }
    }
    return K.back().back();

}



int main (void)
{
    std::vector<Item> items;
    items.push_back({1,8});
    items.push_back({2,1});
    items.push_back({3,0});
    items.push_back({2,5});
    items.push_back({2,3});
    int W = 4;

    auto max_val_with_rep = knapsack_with_repetition(items, W);
    auto max_val_with_no_rep = knapsack_without_repetition(items, W);
    std::cout << max_val_with_rep << std::endl;
    std::cout << max_val_with_no_rep << std::endl;
    return 0;
}
