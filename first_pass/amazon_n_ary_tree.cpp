#include <iostream>
#include <vector>
#include <cassert>
#include "utils.hpp"

struct Node
{
    int id;
    std::vector<Node*> nodes;
};

std::ostream& operator<< (std::ostream& out, const Node& node)
{
    out << node.id;
    return out;
}


Node* find_common_ancestor_helper (Node *root, Node* A, Node* B)
{
    if (!root) {
        return nullptr;
    } else if (root->id == A->id || root->id == B->id) {
        return root;
    }
    
    Node* found_a = nullptr;
    Node* found_b = nullptr;
    Node* found = nullptr;
    for (const auto node: root->nodes) {
        //debug(*node);
        found = find_common_ancestor_helper(node, A, B);
        if (found) {
            if (found->id == A->id) {
                //debug(*found);
                found_a = found;
            } else if (found->id == B->id) {
                //debug(*found);
                found_b = found;
            } else {
                //debug(*found);
                return found;
            }
        }
        if (found_a && found_b) {
            return root;
        }
    }
    return found_a ? found_a : found_b;
}

Node* find_common_ancestor (Node *root, Node* A, Node* B)
{
    //add input validation...
    return find_common_ancestor_helper(root, A, B);
}

int main (void)
{
    Node n0{0,{}};
    Node n1{1,{}};
    Node n2{2,{}};
    Node n3{3,{}};
    Node n4{4,{}};
    Node n5{5,{}};
    Node n6{6,{}};
    Node n7{7,{}};
    Node n8{8,{}};
    Node n9{9,{}};
    Node n10{10,{}};
    Node n11{11,{}};
    Node n12{12,{}};
    Node n13{13,{}};
    Node n14{14,{}};
    Node n15{15,{}};

    Node n16{16, {}};

    n0.nodes.emplace_back(&n1);
    n0.nodes.emplace_back(&n2);
    n0.nodes.emplace_back(&n3);

    n1.nodes.emplace_back(&n4);
    
    n2.nodes.emplace_back(&n5);
    n2.nodes.emplace_back(&n6);

    n3.nodes.emplace_back(&n7);
    n3.nodes.emplace_back(&n8);
    n3.nodes.emplace_back(&n9);

    n4.nodes.emplace_back(&n10);
    n4.nodes.emplace_back(&n11);
    n4.nodes.emplace_back(&n12);

    n6.nodes.emplace_back(&n13);
    n6.nodes.emplace_back(&n14);
    n6.nodes.emplace_back(&n15);



    auto res = find_common_ancestor(&n0, &n5, &n14);
    assert(res != nullptr);
    assert(res->id == 2);

    res = find_common_ancestor(&n0, &n5, &n2);
    assert(res != nullptr);
    assert(res->id == 2);


    res = find_common_ancestor(&n0, &n5, &n2);
    assert(res != nullptr);
    assert(res->id == 2);

    res = find_common_ancestor(&n0, &n0, &n11);
    assert(res != nullptr);
    assert(res->id == 0);

    return 0;
}
