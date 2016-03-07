#ifndef __BTREE_HPP__
#define __BTREE_HPP__


#include <iostream>
#include <memory>


//check es 9.10

template <class T>
struct BTN {
    int id;
    T data;
    std::shared_ptr<BTN<T>> left;
    std::shared_ptr<BTN<T>> right;
};

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

    return a;




}


#endif
