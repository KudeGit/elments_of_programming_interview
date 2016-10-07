#include <iostream>
#include <memory>
#include <unordered_map>
#include <stdexcept>

template <class T>
struct UnionNode {
    int rank;
    std::shared_ptr<T> data;
    std::shared_ptr<UnionNode<T>> parent;
};


template <class T>
struct Union {
    std::shared_ptr<UnionNode<T>> root = nullptr;
    std::unordered_map<std::shared_ptr<T>, std::shared_ptr<UnionNode<T>>> data_to_node;

    void makeset (const std::shared_ptr<T>& data);
    std::shared_ptr<UnionNode<T>> find (const std::shared_ptr<UnionNode<T>>& curr);
    std::shared_ptr<T> find (const std::shared_ptr<T>& data) {
        auto& x = data_to_node[data];
        if (!x) {
            data_to_node.erase(data);
            throw std::logic_error("data not present");
        }
        auto union_node = find(x);
        return union_node->data;
    }
    void union_find (const std::shared_ptr<T>& x, const std::shared_ptr<T>& y);
};


template <class T>
void Union<T>::makeset (const std::shared_ptr<T>& data)
{
    auto& x = data_to_node[data];
    if(x) {
        throw std::logic_error("node already present");
    }
    x = std::make_shared(UnionNode<T>{data, nullptr});
    x->parent = x;

}

template <class T>
std::shared_ptr<UnionNode<T>> Union<T>::find(const std::shared_ptr<UnionNode<T>>& curr)
{
    //implementing path compression directly
    if (curr->parent != curr) {
        curr->parent = find(curr->parent);
    }
    return curr->parent;
}

template <class T>
void Union<T>::union_find (const std::shared_ptr<T>& x, const std::shared_ptr<T>& y)
{
    auto& xu = data_to_node[x];
    if (!xu) {
        data_to_node.clear(x);
        throw std::logic_error("node not present");
    }
    auto& yu = data_to_node[y];
    if (!yu) {
        data_to_node.clear(y);
        throw std::logic_error("node not present");
    }
    
    auto rx = find(xu);
    auto ry = find(yu);
    if (rx == ry) {
        return;
    } else {
        if (rx->rank > ry->rank) {
            ry->parent = rx;
        } else {
            rx->parent = ry;
            if (rx->rank == ry->rank) {
                ++ry->rank;
            }
        }
    }
}

