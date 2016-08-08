#include <iostream>
#include <vector>
#include <limits>
#include <cassert>
#include "utils.hpp"


size_t get_next_pow2k (size_t n)
{
    --n;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    ++n;
    return n + (n == 0);
}

template <class T>
class SegmentTree {
    private:
        size_t n;
        std::vector<T> seg_tree;
        void swap(SegmentTree<T>& other) {std::swap(seg_tree, other.seg_tree);}
        T insert_helper (const std::vector<T>& input, const int l, const int r, const int pos);
        T getMinHelper (const int left, const int right, const int qleft, const int qright, const int pos);
    public:
        SegmentTree& operator=(SegmentTree<T> other) {
            swap(other);
            return *this;
        }
        SegmentTree() : n(0), seg_tree(0) {}
        SegmentTree(const std::vector<T>& input);
        SegmentTree(const SegmentTree<T>& other): n(other.n), seg_tree(other.seg_tree) {}
        SegmentTree(const SegmentTree<T>&& other): n(other.n), seg_tree(std::move(other.seg_tree)) {
            other.n = 0;
        }
        SegmentTree(SegmentTree<T>& other): n(other.n), seg_tree(other.seg_tree) {}
        T getMin(const int qleft, const int qright);
        ~SegmentTree() {}
        void print_internal_state (void) {
            std::cout << seg_tree << std::endl;
        }
};

template <class T>
T SegmentTree<T>::getMinHelper (const int left, const int right, const int qleft, const int qright, const int pos)
{
    if (qleft <= left && right <= qright) {
        return seg_tree[pos];
    } else if (qleft > right || qright < left) {
        return std::numeric_limits<T>::max();
    } else {
        auto middle = left + ((right - left)>>1);
        auto x = getMinHelper(left, middle, qleft, qright, (pos << 1) + 1);
        auto y = getMinHelper(middle+1, right,  qleft, qright, (pos << 1) + 2);
        return std::min(x,y);
    }
}

template <class T>
T SegmentTree<T>::getMin (const int qleft, const int qright)
{
    return qleft <= qright ? getMinHelper(0, n-1, qleft, qright, 0) : std::numeric_limits<T>::max();
}

template <class T>
T SegmentTree<T>::insert_helper (const std::vector<T>& input, const int l, const int r, const int pos)
{
    assert(pos < seg_tree.size());
    if (l >= r) {
        //debug(l);
        //debug(r);
        //debug(pos);
        seg_tree[pos] = l < input.size() ?  input[l] : std::numeric_limits<T>::max();
    } else {
        auto m = l + ((r - l) >> 1);
        auto x = insert_helper(input, l, m, (pos << 1) + 1);
        auto y = insert_helper(input, m+1, r, (pos << 1) + 2);
        seg_tree[pos] = std::min(x,y);
    }
    //debug(seg_tree[pos]);
    return seg_tree[pos];
}

template <class T>
SegmentTree<T>::SegmentTree (const std::vector<T>& input)
{
    n = input.size();
    n = get_next_pow2k(input.size());
    seg_tree = std::move(std::vector<T>(2*n - 1, std::numeric_limits<T>::max()));
    insert_helper(input, 0, n-1, 0);
}






int main (void)
{
    std::vector<int> input = {3,-1,5,6,-100};
    SegmentTree<int> T(input);
    T.print_internal_state();
    for (int i = 0; i < input.size(); ++i) {
        for (int j = i; j < input.size(); ++j) {
            std::cout << "min(" <<  i << ", " << j << "): " << T.getMin(i,j) << std::endl;
        }
    }
    return 0;
}

