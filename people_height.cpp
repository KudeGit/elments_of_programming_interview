#include <iostream>
#include <vector>
#include <set>
#include "utils.hpp"


struct Person {
    int height;
    int inFront;
};

std::ostream& operator<< (std::ostream& out, const Person& p)
{
    out << "(" << p.height  << ", " << p.inFront << ")";
    return out;
}


struct TN {
    int val = 1;
    Person p;
    TN* left = nullptr;
    TN* right = nullptr;
};

void insertTree (TN* root, Person& p, int val)
{
    if (!root) {
        return;
    } else if (val < root->val) {
        if (!root->left) {
            root->left = new TN();
            root->left->val = 1;
            root->left->p = p;
        } else {
            insertTree(root->left, p, val);
        }
        ++root->val;
    } else {
        if (!root->right) {
            root->right = new TN();
            root->right->val = 1;
            root->right->p = p;
        } else {
            insertTree(root->right, p, val - root->val);
        }
    }
}




TN* insert (const std::vector<int>& A, const std::vector<int> B)
{
    if (A.size() != B.size()) {
        return nullptr;
    }
    if (A.empty()) {
        return nullptr;
    }
    std::vector<Person> people;
    for (int i = 0; i < A.size(); ++i) {
        people.emplace_back(Person{A[i], B[i]});
    }
    std::sort(people.begin(), people.end(),
            [](const Person& a, const Person& b) {
                return a.height > b.height;
        });
    TN* root = new TN();
    root->p = people[0];
    for (int i = 1; i < people.size(); ++i) {
        insertTree(root, people[i], people[i].inFront);
    }
    return root;
}

void in_order (TN* root, std::vector<int>& res)
{
    if (!root) {
        return;
    }
    in_order(root->left, res);
    res.emplace_back(root->p.height);
    in_order(root->right, res);
}

int main (void)
{
    std::vector<int> A = {5, 3, 2, 6, 1, 4};
    std::vector<int> B = {0, 1, 2, 0, 3, 2};
    auto root = insert(A, B);
    std::vector<int> res; 
    in_order(root, res);
    std::cout << res << std::endl;
    return 0;
}


