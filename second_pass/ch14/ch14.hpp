#ifndef __CH_14__
#define __CH_14__

#include <vector>
#include <string>

std::vector<int> unique_elements_in_sorted_array (const std::vector<int>& A);
std::vector<int> compute_intersection(const std::vector<int>& A, const std::vector<int>& B);
void merge_in_place (std::vector<int>& A, int NA, const std::vector<int>& B);


using Event = std::pair<std::size_t, std::size_t>;
std::vector<int> minimum_covering (const std::vector<Event> events);

void sort_by_key (std::vector<int>& A);
int smallest_nonconstructible_change (std::vector<int>& coins);


int search_completeness (int budget, std::vector<int>& A);
void indirect_sort (const std::string& ifilename, const std::string& ofilename);

template <class T>
void sort_min_distance (std::vector<T>& A);

template <class T>
void apply_permutation (std::vector<T>& A, std::vector<int>& P)
{
    for (int i = 0; i < A.size(); ++i) {
        if (P[i] >= 0) {
            auto a = i;
            auto tmp_a = A[a];
            do {
                auto next_a = P[a];
                auto next_tmp_a = A[next_a];
                A[next_a] = tmp_a;
                P[a] -= P.size();
                a = next_a; tmp_a = next_tmp_a;
            } while(a != i);
        }
    }
    for_each(P.begin(), P.end(), [&P](int& p) { p += P.size();});
}

template <class T>
void sort_min_distance (std::vector<T>& A)
{
    std::vector<std::pair<int,T&>> AA;
    for (auto i = 0; i < A.size(); ++i) {
        AA.emplace_back(i, A[i]);
    }
    std::sort(AA.begin(), AA.end(),
            [](const std::pair<int, T&>& lhs, const std::pair<int, T&>& rhs) {
                return lhs.second < rhs.second;
            });
    std::vector<int> P;
    for_each(AA.begin(), AA.end(),[&P](const std::pair<int,T&>& a) {
                P.emplace_back(a.first);
            });

    apply_permutation(A, P);
}


#endif //__CH_14__
