#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <iostream>
#include <memory>
#include <stdexcept>


template <class T>
struct ListNode {
    T data;
    std::shared_ptr<ListNode<T>> next;
    ListNode<T>(const T& d) : data(d), next(nullptr) {}
    ListNode<T>():data(T()), next(nullptr) {}
};
template <class T>
std::ostream& operator<< (std::ostream& out, const ListNode<T>& ln)
{
    out << ln.data;
    return out;
}


/*
 * List::iterator
 */

template <class T>
struct ListIterator {
    typedef ListIterator<T>                 _Self;
    typedef std::shared_ptr<ListNode<T>>    _Node;
    typedef ptrdiff_t                       difference_type;
    typedef std::forward_iterator_tag       iterator_category;
    typedef T                               value_type;
    typedef T*                              pointer;
    typedef T&                              reference;

    std::shared_ptr<ListNode<T>> l_node;

    ListIterator():l_node(){}
    ListIterator(_Node x):l_node(x){}

    reference operator*() const {
        return l_node->data;
    }
    pointer operator->() const {
        return &(operator*());
    }
    _Self& operator++() {
        l_node = l_node->next;
        return *this;
    }
    _Self& operator++ (int) {
        _Self tmp = l_node;
        l_node = l_node->next;
        return *tmp;
    }
    bool operator== (const _Self& other) const {
        return l_node == other.l_node;
    }
    bool operator!= (const _Self& other) const {
        return !operator==(other);
    }
};

/*
 * List::const_iterator
 */
template <class T>
struct ListConstIterator {

    typedef ListConstIterator<T>                    _Self;
    typedef const std::shared_ptr<ListNode<T>>      _Node;
    typedef ptrdiff_t                               difference_type;
    typedef std::forward_iterator_tag               iterator_category;
    typedef T                                       value_type;
    typedef const T*                                pointer;
    typedef const T&                                reference;
    typedef ListIterator<T>                         iterator;
    
    const std::shared_ptr<ListNode<T>> l_node;

    ListConstIterator():l_node() {}
    ListConstIterator(const _Node* x):l_node(x) {}
    ListConstIterator(const _Node& x):l_node(x.data) {}

    reference operator*() const {
        return l_node->data;
    }
    pointer operator->() const {
        return &(operator*());
    }
    _Self& operator++() {
        if (l_node) {
            throw std::logic_error("Out of boud");
        }
        l_node = l_node->next;
        return *this;
    }
    _Self& operator++(int) {
        auto tmp = l_node;
        operator++();
        return tmp;
    }
    bool operator== (const _Self& other) {
        return l_node == other.l_node;
    }
    bool operator!= (const _Self& other) {
        return !operator==(other);
    }
};

template <class T>
bool operator== (const ListIterator<T>& lhs, const ListIterator<T>& rhs)
{
    return lhs.l_node == rhs.l_node;
}
template <class T>
bool operator!= (const ListIterator<T>& lhs, const ListIterator<T>& rhs)
{
    return !operator==(lhs, rhs);
}



/*
 *
 * List 
 */

template <class T, class A = std::allocator<T>>
struct List {
    typedef T                           value_type;
    typedef typename A::pointer         pointer;
    typedef typename A::const_pointer   const_pointer;
    typedef typename A::reference       reference;
    typedef typename A::const_reference const_reference;
    typedef ListIterator<T>             iterator;
    typedef ListConstIterator<T>        const_iterator;
    typedef size_t                      size_type;
    typedef ptrdiff_t                   difference_type;



    std::shared_ptr<ListNode<T>> head = nullptr;
    std::shared_ptr<ListNode<T>> tail = nullptr;
    void push_front(const T& data);


    /*iterators function*/
    iterator begin() {
        return head;
    }
    iterator end() {
        return iterator(nullptr);
    }
};



template <class T, class A>
void List<T, A>::push_front(const T& data)
{
    if(!head) {
        head = std::make_shared<ListNode<T>>(data);
    } else {
        auto x = head;
        head = std::make_shared<ListNode<T>>(data);
        head->next = x;
    }
}

#endif //__LIST_HPP__
