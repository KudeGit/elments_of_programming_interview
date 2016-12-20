#include <iostream>
#include <string>
#include <vector>


//tested on leetcode

using namespace std;

int minDistance(const string& word1, const string& word2) {
    std::vector<std::vector<int>> K(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
    for (int i = 0; i < K[0].size(); ++i) {
        K[0][i] = i;
    }
    for (int i = 0; i < K.size(); ++i) {
        K[i][0] = i;
    }
    for (int i = 0, ii = 1; i < word1.size(); ++i, ++ii) {
        for (int j = 0, jj = 1; j < word2.size(); ++j, ++jj) {
            K[ii][jj] = std::min(K[ii][jj-1] + 1, K[ii-1][jj] + 1);
            K[ii][jj] = std::min(K[ii][jj], K[ii-1][jj-1] + (word1[i] == word2[j] ? 0 : 1));
        }
    }
    return K.back().back();
}


int main (void)
{
    return 0;
}
