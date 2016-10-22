#include <iostream>
#include <vector>

class TournamentTree {
    private:
        struct Player {
            double force;
            int id;
        };
        std::vector<Player> tree;
        void insertHelper (int node, int id, double force) {
            int left = (node << 1)  + 1, right = (node << 1) + 2;
            if (left < tree.size()) {
                insertHelper(tree[left].id == - 1 ? left : right, id, force);
                tree[node].id = tree[left].force > tree[right].force ? 
                    tree[left].id : tree[right].id;
                tree[node].force = std::max(tree[left].force, tree[right].force);
            } else {
                tree[node].force = force;
                tree[node].id = id;
            }
        }

    public: 
        TournamentTree(int n) : tree(std::vector<Player>((n << 1)- 1, {0, -1})) {}
        void insert(int id, double force) { insertHelper(0, id, force);}
        int getWinner () {
            if (tree[0].id == -1) {
                throw std::logic_error("Invalid id in node 0... probably not all player were inserted");
            }
            return tree[0].id;
        }

};
