#ifndef __UTILS__

#define __UTILS__

#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#define MAX(x,y) (((x) < (y)) ? (x) : (y))

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <tuple>


template <typename T, std::size_t M, std::size_t N>
std::ostream& operator<< (std::ostream& out, T (&A)[M][N])
{
    for (int i = 0; i < M; ++i) {
        for (int j =0; j < N; ++j) {
            out <<  A[i][j] << "\t";
        }
        out << std::endl;
    }
    return out;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T> &L)
{
    for (const auto &l: L) {
        out << l << ", ";
    }
    return out;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::list<T> &L)
{
    for (const auto &l: L) {
        out << l << ", ";
    }
    return out;
}

template <typename T>
std::ostream& operator<< (std::ostream& out,  std::unordered_set<T> &L)
{
    for (const auto &l: L) {
        out << l << ", ";
    }
    return out;
}

template <typename X, typename Y>
std::ostream& operator<< (std::ostream& out, const std::unordered_map<X,Y> &map)
{
    for (const auto &m: map) {
        out <<"(" << m.first << ", " << m.second << "), ";
    }
    return out;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::tuple<T,T> &t)
{
    out << "(" << std::get<0>(t) << ", " << std::get<1>(t) << ")"; 
    return out;
}

#define debug(x) do{std::cout << #x <<": " << x << std::endl; std::cin.get();}while(0)

#endif
