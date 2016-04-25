#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>


template <class T, class HashKey, class KeyEq>
bool find_closest_pair (const std::vector<T>& A, T& res)
{
    std::unordered_map<T, int, HashKey, KeyEq> last_pos;
    int min_distance = std::numeric_limits<int>::max();

    for (int i = 0; i < A.size(); ++i) {
        if (last_pos.find(A[i]) == last_pos.end()) {
            last_pos[A[i]] = i;
        } else {
            if (i - last_pos[A[i]] < min_distance) {
                res = A[i];
                min_distance = i - last_pos[A[i]];
            }
        }
    }
    if (min_distance == std::numeric_limits<int>::max()) {
        return false;
    }
    return true;
}


int main (void)
{
    std::vector<std::string> words = {
        "All", "work", "and", "no", "play", "makes", "for", "no",
        "work", "no", "fun", "and", "no", "result" };
    std::string res;
    auto found = find_closest_pair<std::string, 
         std::hash<std::string>,
         std::equal_to<std::string>>(words, res);
    if (found) {
        std::cout <<  res << std::endl;
    }
    return 0;
}
