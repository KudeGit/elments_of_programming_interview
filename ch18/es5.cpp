#include <iostream>
#include <vector>
#include "../utils.hpp"


class TournamentTree {
    private:
        struct TreeNode {
            double max_left_capacity;
            std::vector<int> items;
        };
        friend std::ostream& operator<< (std::ostream& out, const TreeNode& tn) {
            out << tn.max_left_capacity << "(" << tn.items << ")";
            return out;
        }
        std::vector<TreeNode> tree;
        void insert_helper(int root, int item, double capacity);
        void print_box_capacity_helper (int root);

    public:
        TournamentTree (int n, double capacity) : tree(std::vector<TreeNode>((n << 1) - 1, {capacity})) {}
        void insert (int item, double capacity) {
            insert_helper(0, item, capacity);
        }
        void print_box_capacity () {
            print_box_capacity_helper(0);
            std::cout << std::endl;
        }
};



void TournamentTree::insert_helper (int root, int item, double capacity)
{
    int left = (root << 1) + 1;
    int right = (root << 1) + 2;
    if (left < tree.size()) { //internal node;
        insert_helper (capacity <= tree[left].max_left_capacity ? left : right, item, capacity);
        tree[root].max_left_capacity = std::max(tree[left].max_left_capacity, 
                tree[right].max_left_capacity);
    } else { //leaf node
        tree[root].max_left_capacity -= capacity;
        tree[root].items.push_back(item);
    }
}


void TournamentTree::print_box_capacity_helper (int root)
{
    int left = (root << 1) + 1, right = (root << 1) + 2;
    if (left < tree.size()) {
        print_box_capacity_helper(left);
        print_box_capacity_helper(right);
    } else {
        std::cout <<  tree[root] << ", ";
    }
}


int main(void)
{
    TournamentTree T(6, 1);
    T.insert(1, 0.6);
    T.insert(2, 0.6);
    T.insert(3, 0.55);
    T.insert(4, 0.8);
    T.insert(5, 0.5);
    T.print_box_capacity();

    return 0;
}
