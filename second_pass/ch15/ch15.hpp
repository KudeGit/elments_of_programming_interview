#ifndef __CH_15__
#define __CH_15__

#include <memory>
#include <functional>
#include <vector>
#include "../../utils.hpp"
template <class T>
struct BSTNode {
    T val;
    std::unique_ptr<BSTNode<T>> left = nullptr;
    std::unique_ptr<BSTNode<T>> right = nullptr;
};

template <class T, class F>
void pre_order_visit(const BSTNode<T>* root, F f) {
    if (!root) {
        return;
    }
    f(root);
    pre_order_visit(root->left.get(), f);
    pre_order_visit(root->right.get(), f);
}

template <class T, class F>
void in_order_visit(const BSTNode<T>* root, F f) {
    if (!root) {
        return;
    }
    in_order_visit(root->left.get(), f);
    f(root);
    in_order_visit(root->right.get(), f);
}


template <class T>
BSTNode<T>* find_recursive (BSTNode<T>* root, const T& key)
{
    if (!root) {
        return nullptr;
    }
    if (root->val == key) {
        auto candidate = find_recursive(root->left.get(), key);
        return candidate ? candidate : root;
    }
    return find_recursive(key < root->val ?
                            root->left.get() : root->right.get(), key);

}
template <class T>
BSTNode<T>* find_iterative (BSTNode<int>* root, const T& key)
{
    BSTNode<T>* candidate = nullptr;
    while (root) {
        if (key == root->val) {
            candidate = root;
            root = root->left.get();
        } else {
            root = key < root->val ? root->left.get() : root->right.get();
        }
    }
    return candidate;
}

template <class T>
void find_k_largest_helper (BSTNode<T>* root, const int k,
        std::vector<BSTNode<T>*>& res)
{
    if (!root) {
        return;
    }

    find_k_largest_helper(root->right.get(), k, res);
    if (res.size() < k) {
        res.emplace_back(root);
    }
    find_k_largest_helper(root->left.get(), k, res);
}

template <class T>
std::vector<BSTNode<T>*> find_k_largest (BSTNode<T>* root, int k)
{
    std::vector<BSTNode<T>*> res;
    find_k_largest_helper(root, k, res);
    return res;
}



template <class T>
std::unique_ptr<BSTNode<T>> rebuild_from_preorder_helper (
        const std::vector<T>& preorder,
        const int l, const int r)
{
    if (l > r) {
        return nullptr;
    }
    int i = l + 1;
    while (i < r && preorder[i] <= preorder[l]) {
        ++i;
    }
    auto left = rebuild_from_preorder_helper(preorder, l+1, i-1);
    auto right = rebuild_from_preorder_helper(preorder, i, r);
    return std::make_unique<BSTNode<T>>(BSTNode<T>{preorder[l],
            std::move(left), std::move(right)});
}

template <class T>
std::unique_ptr<BSTNode<T>> rebuild_from_preorder (const std::vector<T>& preorder)
{
    return rebuild_from_preorder_helper (preorder, 0, preorder.size() - 1);
}



int min_distance_3_sorted_array (const std::vector<std::vector<int>>& A);

template<class T>
std::unique_ptr<BSTNode<T>> rebuild_from_sorted_vector_helper(const std::vector<T>& A, const int l, const int r)
{
    if (l > r) {
        return nullptr;
    }
    auto m = l + ((r - l) >> 1);
    auto left = rebuild_from_sorted_vector_helper(A, l , m - 1);
    auto right = rebuild_from_sorted_vector_helper(A, m + 1, r);
    auto root = std::make_unique<BSTNode<T>>(BSTNode<T>{A[m], std::move(left), std::move(right)});
    return root;
}


template <class T>
std::unique_ptr<BSTNode<T>> rebuild_from_sorted_vector (const std::vector<T>& A)
{
    return rebuild_from_sorted_vector_helper (A, 0, A.size() - 1);
}


template <class T>
struct ListNode {
    T val;
    ListNode<T>* next;
};


template <class T>
std::unique_ptr<BSTNode<T>> rebuild_from_sorted_list_helper (ListNode<T>*& head,
        const long int l, const long int r)
{
    if (l > r) {
        return nullptr;
    }
    auto m = l + ((r - l) >> 1);
    auto left = rebuild_from_sorted_list_helper(head, l, m-1);
    auto curr_root = std::make_unique<BSTNode<T>>();
    curr_root->val = head->val;
    curr_root->left = std::move(left);
    head = head->next;
    curr_root->right = std::move(rebuild_from_sorted_list_helper(head, m+1, r));
    return curr_root;
}
template <class T>
std::unique_ptr<BSTNode<T>> rebuild_from_sorted_list (ListNode<T>* head)
{
    long int n = 0;
    auto x = head;
    while (x) {
        x = x->next;
        ++n;
    }
    return rebuild_from_sorted_list_helper(head, 0, n-1);
}

template <class T>
BSTNode<T>* find_successor_rec (BSTNode<T>* root, const T& target)
{
    if (!root) {
        return nullptr;
    }
    if (target < root->val) {
        auto candidate = find_successor_rec(root->left.get(), target);
        return candidate ? candidate : root;
    } else {
        return find_successor_rec(root->right.get(), target);
    }
}

template <class T>
BSTNode<T>* find_successor (BSTNode<T>* root, const T& target)
{
    BSTNode<T>* candidate = nullptr;
    while (root) {
        if (target < root->val) {
            candidate = root;
            root = root->left.get();
        } else {
            root = root->right.get();
        }
    }
    return candidate;
}


template <class T>
BSTNode<T>* find_predecessor (BSTNode<T>* root, const T& target)
{
    BSTNode<T>* candidate = nullptr;
    while (root) {
        if (target > root->val) {
            candidate = root;
            root = root->right.get();
        } else {
            root = root->left.get();
        }
    }
    return candidate;
}

template <class T>
BSTNode<T>* find_predecessor_rec (BSTNode<T>* root, const T& target)
{
    if (!root) {
        return nullptr;
    }
    if (target > root->val) {
        auto candidate = find_predecessor_rec(root->right.get(), target);
        return candidate ? candidate : root;
    } else {
        return find_predecessor_rec(root->left.get(), target);
    }
}

template <class T>
std::vector<BSTNode<T>*> find_nodes_in_range (BSTNode<T>* root, int L, int U)
{
    if (!root) {
        return {};
    }
    std::vector<BSTNode<T>*> res;
    for (auto it = find_successor(root, L);
            it && it->val < U;
            it = find_successor(root, it->val)) {
        res.emplace_back(it);
    }
    return res;
}

///////////////////////////////////////////
std::unique_ptr<BSTNode<int>> build_fig1();
std::unique_ptr<BSTNode<int>> build_fig2();
std::unique_ptr<BSTNode<int>> build_simple_bst();


#endif //__CH_15__
