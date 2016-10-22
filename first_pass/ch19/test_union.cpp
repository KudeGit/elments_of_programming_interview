#include <iostream>
#include "../utils.hpp"
#include "Union.hpp"
#include <cassert>

int main (void)
{
    Union<int> U;
    auto A = std::make_shared<int>(1);
    auto B = std::make_shared<int>(2);
    auto C = std::make_shared<int>(3);
    auto D = std::make_shared<int>(4);
    auto E = std::make_shared<int>(5);
    auto F = std::make_shared<int>(6);
    auto G = std::make_shared<int>(7);
    
    U.makeset(A);
    U.makeset(B);
    U.makeset(C);
    U.makeset(D);
    U.makeset(E);
    U.makeset(F);
    U.makeset(G);
    std::cout << U << std::endl;


    auto f = U.find(F);
    assert (f == F);
    auto c = U.find(C);
    assert (c == C);
    U.union_find(C,F);
    f = U.find(F);
    c = U.find(C);
    assert(c == f);
    assert(c == F);


    auto e = U.find(E);
    assert (e == E);
    auto b = U.find(B);
    assert (b == B);
    U.union_find(B,E);
    e = U.find(E);
    b = U.find(B);
    assert(b == e);
    assert(b == E);


    auto a = U.find(A);
    assert (a == A);
    auto d = U.find(D);
    assert (d == D);
    U.union_find(D,A);
    a = U.find(A);
    d = U.find(D);
    assert(d == a);
    assert(d == A);

    std::cout << U << std::endl;

    U.union_find(E,A);
    d = U.find(D);
    a = U.find(A);
    e = U.find(E);
    b = U.find(B);
    assert(d == a && e == b && a == e);
    std::cout << U << std::endl;


    U.union_find(F,G);
    auto g = U.find(G);
    f = U.find(F);
    c = U.find(C);
    assert(g == f && c == g);

    U.union_find(B,G);
    a = U.find(A);
    b = U.find(B);
    c = U.find(C);
    d = U.find(D);
    e = U.find(E);
    f = U.find(F);
    g = U.find(G);
    assert(a == b && c == a && d == a && e == a && f == a && g == a);
    std::cout << U << std::endl;

    return 0;
}
