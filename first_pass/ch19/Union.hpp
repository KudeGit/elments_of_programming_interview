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

template<class T>
std::ostream& operator<< (std::ostream& out, const UnionNode<T>& node)
{
    //add the check to see if streamable
    out << "(" << *(node.data) << ", " << 
        node.rank << ", "<< *(node.parent->data) << ")";
    return out;
}


template <class T>
struct Union {
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
        //debug(*union_node);
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
    x = std::make_shared<UnionNode<T>>(UnionNode<T>{0, data, nullptr});
    x->parent = x;

}

template <class T>
std::shared_ptr<UnionNode<T>> Union<T>::find(const std::shared_ptr<UnionNode<T>>& curr)
{
    //debug(*curr);
    //debug(*curr->parent);
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
        data_to_node.erase(x);
        throw std::logic_error("node not present");
    }
    auto& yu = data_to_node[y];
    if (!yu) {
        data_to_node.erase(y);
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
                ++(ry->rank);
            }
        }
    }
}

template<class T>
std::ostream& operator<< (std::ostream& out, const Union<T>& U)
{
    for (const auto& node_pair: U.data_to_node) {
        out << "[" << *(node_pair.first) << ", " << *(node_pair.second) << "], ";
    }
    return out;
}
