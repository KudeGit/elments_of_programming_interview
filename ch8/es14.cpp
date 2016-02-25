#include <iostream>
#include "list.hpp"
#include "../utils.hpp"
#include <vector>
#include <random>


template <class T>
struct PostListNode {
    T data;
    std::shared_ptr<PostListNode<T>> jump = nullptr;
    std::shared_ptr<PostListNode<T>> next = nullptr;
    PostListNode<T>() {};
    PostListNode<T>(const T& data) : data(data) {};
    PostListNode<T>(const PostListNode<T>& other): data(other.data) {};
    PostListNode<T>(PostListNode<T>&& other) : data(std::move(other.data)) {};
    ~PostListNode<T>() {}
};


template <class T>
std::ostream& operator<< (std::ostream& out, const PostListNode<T>& n)
{
    out << "(" << n. data << ", " << (n.jump ? n.jump->data : 0)  <<  ")";
    return out;
}

template <class T>
void print_post_list (std::shared_ptr<PostListNode<T>> head)
{
    while(head) {
        std::cout << *head << ", ";
        head = head->next;
    }
    std::cout << std::endl;
    return;
}

template <class T>
std::shared_ptr<PostListNode<T>> copy_posting_list (std::shared_ptr<PostListNode<T>> head)
{
    if (!head) {
        return nullptr;
    }
    std::shared_ptr<PostListNode<T>> new_head = nullptr;
    std::shared_ptr<PostListNode<T>> new_curr = nullptr;
    auto curr = head;
    //allocationg new nodes
    while (curr) {
        new_curr = std::make_shared<PostListNode<T>>(*curr);
        new_head = new_head ? new_head : new_curr;
        new_curr->next = curr->next;
        curr->next = new_curr;
        curr = new_curr->next;
    }
    //copying jump pointers
    curr = head;
    new_curr = curr->next;
    while (new_curr) {
        new_curr->jump = curr->jump ? curr->jump->next : nullptr;
        curr = new_curr->next;
        new_curr = new_curr->next;
        new_curr = new_curr ? new_curr->next : new_curr;
    }

    //restore
    curr = head;
    new_curr = curr->next;
    while (new_curr) {
        curr->next = new_curr->next;
        new_curr->next = curr->next ? curr->next->next : nullptr;
        curr = curr->next;
        new_curr = new_curr->next;
    }
    return new_head;
}


int main (void)
{
    auto head = std::make_shared<PostListNode<int>>(0);
    std::vector<std::shared_ptr<PostListNode<int>>> ptr_jmps;
    for (int i = 1; i < 10; ++i) {
       auto curr = std::make_shared<PostListNode<int>>(i);
       curr->next = head;
       head = curr;
       ptr_jmps.push_back(curr);
    }
    std::random_device rd;
    std::default_random_engine g(rd());
    std::uniform_int_distribution<int> d(0,10);
    auto x = head;
    while (x) {
        int i = d(g);
        x->jump = ptr_jmps[i];
        x = x->next;
    }
    
    
    std::cout << *head << std::endl;

    print_post_list(head);
    auto new_head = copy_posting_list(head);
    print_post_list(head);
    print_post_list(new_head);


    return 0;
}





