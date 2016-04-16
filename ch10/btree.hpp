#ifndef __BTREE_HPP__
#define __BTREE_HPP__


#include <iostream>
#include <memory>
#include <stack>


//check es 9.10

template <class T>
struct BTN {
    int id;
    T data;
    int nodes = 0;
    std::shared_ptr<BTN<T>> left = nullptr;
    std::shared_ptr<BTN<T>> right = nullptr;
    std::weak_ptr<BTN<T>> parent;
};

template <class T>
std::ostream& operator<< (std::ostream& out, const BTN<T>& node)
{
    out << "("<< node.data << ", " << node.nodes << ")";
    return out;
}

std::shared_ptr<BTN<char>> create_tree_balanced (void)
{

    auto a = std::make_shared<BTN<char>>();
    auto b = std::make_shared<BTN<char>>();
    auto c = std::make_shared<BTN<char>>();
    auto d = std::make_shared<BTN<char>>();
    auto e = std::make_shared<BTN<char>>();
    auto f = std::make_shared<BTN<char>>();
    auto g = std::make_shared<BTN<char>>();
    a->data = 'a';
    a->left = b; a->right = c;

    b->data = 'b';
    b->left = d; b->right = e;

    c->data = 'c';
    c->left = f; c->right = g;

    d->data = 'd';
    e->data = 'e';
    f->data = 'f';
    g->data = 'g';
    return a;
}


std::shared_ptr<BTN<char>> create_tree_not_balanced (void)
{

    auto a = std::make_shared<BTN<char>>();
    auto b = std::make_shared<BTN<char>>();
    auto c = std::make_shared<BTN<char>>();
    auto d = std::make_shared<BTN<char>>();
    auto e = std::make_shared<BTN<char>>();
    auto f = std::make_shared<BTN<char>>();
    auto g = std::make_shared<BTN<char>>();
    auto h = std::make_shared<BTN<char>>();
    auto i = std::make_shared<BTN<char>>();
    auto l = std::make_shared<BTN<char>>();
    a->data = 'a';
    a->left = b; a->right = c;

    b->data = 'b';
    b->left = d; b->right = e;

    c->data = 'c';
    c->left = f; c->right = g;

    d->data = 'd';
    
    e->data = 'e'; 
    e->left = h;
    
    f->data = 'f';
    g->data = 'g';
    
    h->data = 'h';
    h->right = i;

    i->data = 'i';
    i->left = l;

    l->data = 'l';
    
    return a;
}




std::shared_ptr<BTN<char>> create_3_unbalanced_tree (void)
{
    auto a = std::make_shared<BTN<char>>();
    a->data = 'a'; a->id = 314;
    auto b = std::make_shared<BTN<char>>();
    b->data = 'b'; b->id = 6;
    auto c = std::make_shared<BTN<char>>();
    c->data = 'c'; c->id = 271;
    auto d = std::make_shared<BTN<char>>();
    d->data = 'd'; d->id = 28;
    auto e = std::make_shared<BTN<char>>();
    e->data = 'e'; e->id = 0;
    auto f = std::make_shared<BTN<char>>();
    f->data = 'f'; f->id = 561;
    auto g = std::make_shared<BTN<char>>();
    g->data = 'g'; g->id = 3;
    auto h = std::make_shared<BTN<char>>();
    h->data = 'h'; h->id = 17;
    auto i = std::make_shared<BTN<char>>();
    i->data = 'i'; i->id = 6;
    auto j = std::make_shared<BTN<char>>();
    j->data = 'j'; j->id = 2;
    auto k = std::make_shared<BTN<char>>();
    k->data = 'k'; k->id = 1;
    auto l = std::make_shared<BTN<char>>();
    l->data = 'l'; l->id = 401;
    auto m = std::make_shared<BTN<char>>();
    m->data = 'm'; m->id = 641;
    auto n = std::make_shared<BTN<char>>();
    n->data = 'n'; n->id = 257;
    auto o = std::make_shared<BTN<char>>();
    o->data = 'o'; o->id = 271; 
    auto p = std::make_shared<BTN<char>>();
    p->data = 'p'; p->id = 28;

    a->left = b; a->right = i;
    b->left = c; b->right = f;
    c->left = d; c->right = e;
    f->right = g;
    g->left = h;

    i->left = j; i->right = o;
    j->right = k;
    k->left = l; k->right = n;
    l->right = m;
    o->right = p;



    b->parent = a; i->parent = a;
    c->parent = b; f->parent = b;
    d->parent = e->parent = c;
    g->parent = f;
    h->parent = g;

    o->parent = j->parent = i;
    k->parent = j;
    l->parent = n->parent = k;
    m->parent = l;
    p->parent = o;

    


    return a;




}

std::shared_ptr<BTN<char>> create_asymmetric_tree2 (void)
{
    auto a = std::make_shared<BTN<char>>();
    a->data = 'a'; a->id = 0;
    auto b = std::make_shared<BTN<char>>();
    b->data = 'b'; b->id = 0;
    auto c = std::make_shared<BTN<char>>();
    c->data = 'c'; c->id = 0;
    auto d = std::make_shared<BTN<char>>();
    d->data = 'd'; d->id = 0;
    auto e = std::make_shared<BTN<char>>();
    e->data = 'b'; e->id = 0;
    auto f = std::make_shared<BTN<char>>();
    f->data = 'c'; f->id = 0;
    auto g = std::make_shared<BTN<char>>();
    g->data = 'e'; c->id = 0;


    a->left = b; a->right = e;
    b->right = c;
    c->right = d;
    e->left = f;
    f->right = g;
    return a;
}


std::shared_ptr<BTN<char>> create_asymmetric_tree1 (void)
{
    auto a = std::make_shared<BTN<char>>();
    a->data = 'a'; a->id = 0;
    auto b = std::make_shared<BTN<char>>();
    b->data = 'b'; b->id = 0;
    auto c = std::make_shared<BTN<char>>();
    c->data = 'c'; c->id = 0;
    auto d = std::make_shared<BTN<char>>();
    d->data = 'd'; d->id = 0;
    auto e = std::make_shared<BTN<char>>();
    e->data = 'b'; e->id = 0;
    auto f = std::make_shared<BTN<char>>();
    f->data = 'c'; f->id = 0;
    auto g = std::make_shared<BTN<char>>();
    g->data = 'e'; c->id = 0;


    a->left = b; a->right = e;
    b->right = c;
    c->right = d;
    e->left = f;
    f->left = g;
    return a;
}


std::shared_ptr<BTN<char>> create_symmetric_tree (void)
{
    auto a = std::make_shared<BTN<char>>();
    a->data = 'a'; a->id = 0;
    auto b = std::make_shared<BTN<char>>();
    b->data = 'b'; b->id = 0;
    auto c = std::make_shared<BTN<char>>();
    c->data = 'c'; c->id = 0;
    auto d = std::make_shared<BTN<char>>();
    d->data = 'd'; d->id = 0;
    auto e = std::make_shared<BTN<char>>();
    e->data = 'b'; e->id = 0;
    auto f = std::make_shared<BTN<char>>();
    f->data = 'c'; f->id = 0;
    auto g = std::make_shared<BTN<char>>();
    g->data = 'd'; c->id = 0;


    a->left = b; a->right = e;
    b->right = c;
    c->right = d;
    e->left = f;
    f->left = g;
    return a;
}




template <class T>
void print_tree_preorder (const std::shared_ptr<BTN<T>>& root)
{
    if (!root) {
        return;
    }
    std::cout << *root << std::endl;
    print_tree_preorder(root->left);
    print_tree_preorder(root->right);
}

template <class T>
void print_tree_inorder (const std::shared_ptr<BTN<T>>& root)
{
    if (!root) {
        return;
    }
    print_tree_inorder(root->left);
    std::cout << *root << std::endl;
    print_tree_inorder(root->right);
}



template <class T>
std::shared_ptr<BTN<T>> find (std::shared_ptr<BTN<T>> root, const T& t)
{
    std::stack<std::shared_ptr<BTN<T>>> S;
    //in order visit with a stack --> no recursion
    while (root || !S.empty()) {
        if(root) {
            S.push(root);
            root = root->left;
        } else {
            root = S.top();
            if (root->data == t) {
                return root;
            }
            S.pop();
            root = root->right;
        }
    }
    return nullptr;
}






std::shared_ptr<BTN<int>> create_int_tree (void)
{
    auto a = std::make_shared<BTN<int>>();
    a->data = 314;
    auto b = std::make_shared<BTN<int>>();
    b->data = 6;
    auto c = std::make_shared<BTN<int>>();
    c->data = 271;
    auto d = std::make_shared<BTN<int>>();
    d->data = 28;
    auto e = std::make_shared<BTN<int>>();
    e->data = 0;
    auto f = std::make_shared<BTN<int>>();
    f->data = 561;
    auto g = std::make_shared<BTN<int>>();
    g->data = 3;
    auto h = std::make_shared<BTN<int>>();
    h->data = 17;
    auto i = std::make_shared<BTN<int>>();
    i->data = 6;
    auto j = std::make_shared<BTN<int>>();
    j->data = 2;
    auto k = std::make_shared<BTN<int>>();
    k->data = 1;
    auto l = std::make_shared<BTN<int>>();
    l->data = 401;
    auto m = std::make_shared<BTN<int>>();
    m->data = 641;
    auto n = std::make_shared<BTN<int>>();
    n->data = 257;
    auto o = std::make_shared<BTN<int>>();
    o->data = 271; 
    auto p = std::make_shared<BTN<int>>();
    p->data = 28;

    a->left = b; a->right = i;
    b->left = c; b->right = f;
    c->left = d; c->right = e;
    f->right = g;
    g->left = h;

    i->left = j; i->right = o;
    j->right = k;
    k->left = l; k->right = n;
    l->right = m;
    o->right = p;



    b->parent = a; i->parent = a;
    c->parent = b; f->parent = b;
    d->parent = e->parent = c;
    g->parent = f;
    h->parent = g;

    o->parent = j->parent = i;
    k->parent = j;
    l->parent = n->parent = k;
    m->parent = l;
    p->parent = o;


    return a;




}


template <class T>
void print_tree_postorder (const std::shared_ptr<BTN<T>>& root) 
{
    if (!root) {
        return;
    }
    print_tree_postorder(root->left);
    print_tree_postorder(root->right);
    std::cout << *root << std::endl;

}



#endif
