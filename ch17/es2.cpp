#include <iostream>
#include <vector>
#include <string>
#include "../utils.hpp"



int min_edit_distance (const std::string& A,
        const std::string& B) 
{
    std::vector<std::vector<int>> dist(A.size() + 1,
            std::vector<int> (B.size() + 1, 0));
    for (int i = 0; i <= A.size(); ++i) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= B.size(); ++j) {
        dist[0][j] = j;
    }
    for (int i = 1; i <= A.size(); ++i) {
        for (int j = 1; j <= B.size(); ++j) {
            int d_ij = A[i-1] == B[j-1] ? 0 : 1;
            dist[i][j] = std::min(
                    std::min(dist[i-1][j] + 1,dist[i][j-1] + 1),
                    dist[i-1][j-1] + d_ij);
        }
    }
    return dist.back().back();
}


int main (void)
{
    std::string s1("saturday");
    std::string s2("sunday");
    auto res = min_edit_distance(s1, s2);
    std::cout << res << std::endl;
    return 0;
}
