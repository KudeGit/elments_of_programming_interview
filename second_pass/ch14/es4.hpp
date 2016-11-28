#include <iostream>
#include <vector>
#include <algorithm>
//solution using stdl
template <class T>
void find_unique_elements (std::vector<T>& A)
{
    std::sort(A.begin(), A.end());
    A.erase(std::unique(A.begin(), A.end()), A.end());
}

//solution remplementing unique in place and erase;
template<class ForwardIterartor>
ForwardIterartor my_unique(ForwardIterartor first, ForwardIterartor last)
{
    if (first == last) {
        return last;
    }
    auto result = first;
    while (++first != last) {
        if (*first != *result) {
            *++result = *first;
        }
    }
    return ++result;
}
