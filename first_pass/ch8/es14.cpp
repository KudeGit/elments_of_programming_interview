#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <stack>
#include <stdexcept> 


template <class T>
struct PostListNode {
    T data;
    int order = -1;
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




template <class T>
void jump_first_order_rec (std::shared_ptr<PostListNode<T>> head, int &order)
{
    if(head && head->order == -1) {
        head->order = order++;
        jump_first_order_rec(head->jump, order);
        jump_first_order_rec(head->next, order);
    }
}

template <class T>
void walk_and_allocate_jump (std::shared_ptr<PostListNode<T>> current,
        std::shared_ptr<PostListNode<T>>& new_head,
        std::unordered_map<std::shared_ptr<PostListNode<T>>, std::shared_ptr<PostListNode<T>>>& cache)
{
    std::shared_ptr<PostListNode<T>> jump_new_prev = nullptr;
    std::shared_ptr<PostListNode<T>> new_node = nullptr;
    while (current && cache.find(current) == cache.end()) {
        new_node = std::make_shared<PostListNode<T>>(*current);
        if(!new_head) {
            new_head = new_node;
        }
        cache[current] = new_node;
        if(jump_new_prev) {
            jump_new_prev->jump = new_node;
        }
        jump_new_prev = new_node;
        current = current->jump;
    }
    if(new_node && current) {
        new_node->jump = cache[current];
    }
}

template <class T>
void update_next_ptr (std::shared_ptr<PostListNode<T>>& head, 
        std::shared_ptr<PostListNode<T>>& new_prev, 
        std::unordered_map<std::shared_ptr<PostListNode<T>>, std::shared_ptr<PostListNode<T>>>& cache)
{
    if (cache.find(head) == cache.end()) {
        throw std::logic_error("node does not exist ???? ");
    }
    auto new_current = cache[head];
    if(new_prev) {
        new_prev->next = new_current;
    }
    new_prev = new_current;
    head = head->next;

}

template <class T>
std::shared_ptr<PostListNode<T>> copy_posting_list_with_cache (std::shared_ptr<PostListNode<T>> head)
{

    std::shared_ptr<PostListNode<T>> new_head = nullptr;
    std::shared_ptr<PostListNode<T>> new_tail = nullptr;
    std::shared_ptr<PostListNode<T>> new_prev = nullptr;
    std::unordered_map<std::shared_ptr<PostListNode<T>>, std::shared_ptr<PostListNode<T>>> cache;
    while(head)  {
        auto current = head;
        walk_and_allocate_jump (head, new_head, cache);
        update_next_ptr(head, new_prev, cache);
    }
    return new_head;
}

template <class T>
void jump_first_order_no_rec(std::shared_ptr<PostListNode<T>> head, int &order)
{
    std::stack<std::shared_ptr<PostListNode<T>>> S;
    S.push(head);
    while (!S.empty()) {
        auto x = S.top(); S.pop();
        if(x && x->order == -1) {
            x->order = order++;
            S.push(x->next);
            S.push(x->jump);
        }
    }
}

template <class T>
void jump_first_order (std::shared_ptr<PostListNode<T>> head)
{
    int order = 0;
    jump_first_order_rec(head, order);
    jump_first_order_no_rec(head, order);

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
    
    
    /*
    auto a = std::make_shared<PostListNode<int>>(0);
    auto b = std::make_shared<PostListNode<int>>(1);
    auto c = std::make_shared<PostListNode<int>>(2);
    auto d = std::make_shared<PostListNode<int>>(3);
    auto e = std::make_shared<PostListNode<int>>(4);
    a->next = b; b->next = c; c->next = d; d->next = e; e->next = nullptr;
    a->jump = b; b->jump = d; d->jump = b; c->jump = a; e->jump = c;
    auto head = a;
*/
    

    std::cout << *head << std::endl;

    print_post_list(head);
    auto new_head = copy_posting_list_with_cache(head);
    print_post_list(head);
    print_post_list(new_head);


    jump_first_order(head);
    return 0;
}





