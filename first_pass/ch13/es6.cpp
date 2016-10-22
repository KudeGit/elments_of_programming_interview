#include <iostream>
#include <unordered_map>
#include <tuple>
#include <vector>
#include "../utils.hpp"


/******* relational operator for pairs<T, int> ******/

template <class T>
using freq_t = std::pair<T, int>;

template <class T>
std::ostream& operator<< (std::ostream& out, const freq_t<T>& f)
{
    out << "(" << f.first << ", " << f.second << ")";
    return out;
}

template <class T>
bool operator== (const freq_t<T>& a, const freq_t<T>& b)
{
    return a.second == b.second;
}

template <class T>
bool operator!= (const freq_t<T>& a, const freq_t<T>& b)
{
    return !operator==(a,b);
}

template <class T>
bool operator< (const freq_t<T>& a, const freq_t<T>& b)
{
    return a.second < b.second;
}

template <class T>
bool operator> (const freq_t<T>& a, const freq_t<T>& b)
{
    return operator<(b, a);
}

template <class T>
bool operator<= (const freq_t<T>& a, const freq_t<T>& b)
{
    return !operator>(a,b);
}

template <class T>
bool operator>= (const freq_t<T>& a, const freq_t<T>& b)
{
    return !operator<(a,b);
}

/***** END relational operator for pairs<T, int> ****/




template <class T>
int partition (std::vector<T>& A, const int start, const int end)
{
    T pivot = A[start];
    int i = start + 1;
    int j = start + 1;
    for (;i <= end; ++i) {
        if (A[i] <= pivot) {
            std::swap(A[i], A[j]);
            ++j;
        }
    }
    --j;
    std::swap(A[start], A[j]);
    return j;
}


template <class T>
void k_selection_helper (std::vector<T>& A, const int K,
        const int start, const int end)
{
    if(start > end) {
        return;
    }
    int idx = partition(A, start, end);
    if (idx == K) {
        return;
    } else {
        if (K < idx) {
            k_selection_helper(A, K, start, idx - 1);
        } else {
            k_selection_helper(A, K, idx + 1, end);
        }
    }
}

template <class T>
void k_selection (std::vector<T>& A, const int K)
{
    k_selection_helper(A, K, 0, A.size() - 1);
}



template <class T>
std::vector<std::pair<T, int>> top_k_entries (const std::vector<T>& entries,
        const int K)
{
    std::unordered_map<T, int> frequencies;
    for (const auto& e: entries) {
        if(frequencies.find(e) == frequencies.end()) {
            frequencies[e] = 1;
        } else {
            ++frequencies[e];
        }
    }
    std::vector<std::pair<T, int>> reduced_entries;
    for (const auto& f: frequencies) {
        reduced_entries.emplace_back(f);
    }
    k_selection(reduced_entries, reduced_entries.size() - 1 - K);
    std::reverse(reduced_entries.begin(), reduced_entries.end());
    while(reduced_entries.size() > K) {
        reduced_entries.pop_back();
    }
    return reduced_entries;
}

int main (void)
{
    std::vector<int> A = {5, 10, 4, 5, 1, 2, 4, 10, 15, 0, 17, 5, 5, 5};
    std::cout << A << std::endl;
    //std::vector<int> B = {5};

    k_selection(A, A.size() - 1 - 2);
    std::cout << A << std::endl;
    auto res = top_k_entries(A, 3);
    //std::cout << res << std::endl;
    for (const auto& r: res) {
        std::cout << r << std::endl;
    }
    return 0;

}
