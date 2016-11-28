#ifndef __INTERVAL_TREE_HPP__
#define __INTERVAL_TREE_HPP__

#include <iostream>
#include <utility>
#include <memory>
#include <utility>

using Event = std::pair<long, long>;


bool overlap(const Event e1, const Event e2)
{
    return e1.first <= e2.second && e1.second >= e2.first;
}


template <class T, class U>
std::ostream& operator<< (std::ostream& out, const std::pair<T,U>& e)
{
    out << "(" << e.first << ", " << e.second << ")";
    return out;
}

struct IntervalTreeNode {
    //simple binary tree;
    std::shared_ptr<Event> e;
    long max_end_time;
    std::unique_ptr<IntervalTreeNode> left;
    std::unique_ptr<IntervalTreeNode> right;
};


std::ostream& operator<< (std::ostream& out, const IntervalTreeNode& itn)
{
    out << "[" << *(itn.e) << "/" << itn.max_end_time << "]";
    return out;
}


struct IntervalTree {
    void insert(const std::shared_ptr<Event> e) {
        if(!root) {
            root = std::make_unique<IntervalTreeNode>(
                    IntervalTreeNode{e, e->second, nullptr, nullptr});
            return;
        }
        auto curr = root.get();
        auto prev = root.get();
        while(curr) {
            prev = curr;
            if (curr->e->first >= e->first) {
                curr = curr->left.get();
            } else {
                curr->max_end_time = std::max(curr->max_end_time, e->second);
                curr = curr->right.get();
            }
        }
        auto itnp = std::make_unique<IntervalTreeNode>(
                    IntervalTreeNode{e, e->second, nullptr, nullptr});
        if (e->first <= prev->e->first) {
            prev->left = std::move(itnp);
        } else {
            prev->right = std::move(itnp);
        }
    }
    template <class U>
    void visit (U u) {
        visit(root.get(), u);
    }
    
    template <class U>
    void search (const Event& target, U u) {
        search(target, root.get(), u);
    }


    private:
    std::unique_ptr<IntervalTreeNode> root;

    template <class U>
    void visit(const IntervalTreeNode* n, U u) {
        if (!n) {
            return;
        }
        visit(n->left.get(), u);
        u(n);
        visit(n->right.get(), u);
    }
    template <class U>
    void search (const Event& e, IntervalTreeNode* root, U u) {
        if (!root) {
            return;
        }
        if (overlap(e, *root->e)) {
            u(*root->e);
        }

        //we search left only if the left node exists and 
        //the maximum recorded is larger that the event start point
        auto search_left = (root->left.get() != nullptr) && 
            root->left.get()->max_end_time >= e.first;
        if (search_left) {
            search(e, root->left.get(), u);
        }
        search(e, root->right.get(), u);
        
    }
};





#endif //__INTERVAL_TREE_HPP__

