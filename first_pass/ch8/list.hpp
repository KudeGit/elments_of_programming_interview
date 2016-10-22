#include <iostream>
#include <memory>
#include <random>
#include <string>

template <class T>
struct ListNode {
    T data;
    std::shared_ptr<ListNode<T>> next = nullptr;
    ListNode<T> (const T& d) : data(d), next(nullptr) {}
    ListNode<T> (const ListNode<T>& other) : data (other.data), next (nullptr) {}
    ListNode<T> (ListNode<T>&& other) : data(std::move(other.data)), next (nullptr) {}
    ~ListNode<T>() {}
};




template<class T>
std::ostream& operator<< (std::ostream& out, const ListNode<T>& node)
{
    out << node.data;
    return out;
}
template<class T>
bool operator== (const ListNode<T>& lhs, const ListNode<T>& rhs)
{
    return operator==(lhs.data, rhs.data);
}
template<class T>
bool operator!= (const ListNode<T>& lhs, const ListNode<T>& rhs)
{
    return !operator==(lhs, rhs);
}

template<class T>
bool operator< (const ListNode<T>& lhs, const ListNode<T>& rhs) 
{
    return lhs.data < rhs.data;
}

template<class T>
bool operator> (const ListNode<T>& lhs, const ListNode<T>& rhs) 
{
    return operator<(rhs, lhs);
}

template<class T>
bool operator<= (const ListNode<T>& lhs, const ListNode<T>& rhs) 
{
    return !operator>(lhs, rhs);
}

template<class T>
bool operator>= (const ListNode<T>& lhs, const ListNode<T>& rhs) 
{
    return !operator<(lhs, rhs);
}
/********************************************************************************/
template <class T>
struct List {
    std::shared_ptr<ListNode<T>> head = nullptr;
    void insert_front (T data);
    void push_back (T data);
    std::shared_ptr<ListNode<T>> get_tail (void);
    void reverse(void);
    List<T>() : head(nullptr) {}
    List<T>(std::shared_ptr<ListNode<T>>& a) : head(a) {}
};

template <class T>
void List<T>::reverse(void)
{
    auto curr = head;
    auto prev = head;
    auto next = head;
    prev = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template <class T>
std::shared_ptr<ListNode<T>> List<T>::get_tail (void)
{
    auto x = head;
    while (x->next) {
        x = x->next;
    }
    return x;
}


template<class T>
std::ostream& operator<< (std::ostream& out, const List<T> l)
{
    auto x = l.head;
    while (x) {
        out << *x << ", ";
        x = x->next;
    }
    return out;
}

template <class T>
void List<T>::insert_front (T data)
{
    auto new_head = std::make_shared<ListNode<T>>(data);
    new_head->next = head;
    head = new_head;
}

template <class T>
void List<T>::push_back (T data)
{
    auto new_last = std::make_shared<ListNode<T>>(data);
    if (head == nullptr) {
        head = new_last;
        return;
    }
    auto x = head;
    while (x->next) {
        x = x->next;
    }
    x->next = new_last;
    return;
}


/************************************************************/

template <class T>
List<T> create_and_populate_list (const int start, const int N)
{
    List<T> l;
    for (int i = 0; i < N; ++i) {
        l.push_back(T(start + i));
    }
    return l;
}

List<int> create_and_populate_list_random (const int start, const int end, const int N)
{
    List<int> l;
    std::random_device rd;
    std::default_random_engine g(rd());
    std::uniform_int_distribution<int> d(start, end);
    for (int i = 0; i < N; ++i) {
        l.push_back(d(g));
    }
    return l;
}


template <class T>
List<T> create_and_populate_list_with_duplicates (const int start, 
        const int N, const int duplciates)
{
    std::random_device rd;
    std::default_random_engine g(rd());
    std::uniform_int_distribution<int> d(1,duplciates);
    List<T> l;
    for (int i = 0; i < N; ++i) {
        for (int j = d(g); j > 0; --j) {
            l.push_back(T(start + i));
        }
    }
    return l;
}


    template <class T>
void advance_head (std::shared_ptr<ListNode<T>>& x, int n) 
{
    while (n && x) {
        --n;
        x = x->next;
    }
}

    template <class T>
int get_len(const List<T>& l) 
{
    auto x = l.head;
    int len = 0;
    while(x) {
        ++len;
        x = x->next;
    }
    return len;
}

    template <class T>
std::shared_ptr<ListNode<T>> overlapping_list (List<T>& l1, List<T>& l2)
{
    std::shared_ptr<ListNode<T>> res;
    int l1_len = get_len(l1);
    int l2_len = get_len(l2);
    auto x = l1.head;
    auto y = l2.head;
    auto delta = l1_len - l2_len;
    delta = delta >= 0 ? delta : -delta;
    advance_head(l1_len >= l2_len ? x : y, delta);
    while (x && y && x->next != y->next) {
        x = x->next;
        y = y->next;
    }
    return x ? x->next : nullptr;
}


    template <class T>
std::shared_ptr<ListNode<T>> find_loop(List<T>& l) 
{
    if(l.head == nullptr) {
        return nullptr;
    }
    auto slow = l.head;
    auto fast = l.head;
    auto loop = false;
    while((slow && fast) && !loop) {
        slow = slow->next;
        fast = fast->next;
        fast = fast ? fast->next : fast;
        loop = fast == slow;
    }
    slow = l.head;
    while (loop && (fast != slow)) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


    template <class T>
void create_loop (List<T>& l, const int pos)
{
    auto x = l.head;
    auto y = l.head;
    auto curr_pos = pos;
    while (x->next) {
        x = x->next;
    }
    while (y && curr_pos) {
        y = y->next;
        --curr_pos;
    }
    if (curr_pos) {
        return;
    }
    x->next = y;
    return;
}



template <class T>
void print_list_from_node (const std::string &str, std::shared_ptr<T> x)
{
    std::cout << str;
    while (x) {
        std::cout << *x << ", ";
        x = x->next;
    }
    std::cout << std::endl;
}
