#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

using std::vector;

auto match_sequence_h (const vector<vector<int>>& A, const vector<int>& S,
        int i, int j, int k, vector<vector<vector<bool>>>& C)
{
    if (k == S.size()) {return true;}
    auto valid_idx = [](const size_t i, const size_t N) {
                            return i < N;
                        };
    if (!valid_idx(i, A.size())) {return false;}
    if (!valid_idx(j, A[i].size())) {return false;}
    if (A[i][j] != S[k]) {return false;}
    if (C[i][j][k]) { return true;}


    vector<std::pair<int, int>> moves = {{-1, 0}, {+1,0}, {0, -1}, {0, +1}};
    auto curr_result = false;
    for (const auto& m: moves) {
        if (match_sequence_h(A, S, i + m.first, j + m.second, k+1, C)) {
            curr_result = true;
            break;
        }
    }
    C[i][j][k] = curr_result;
    return curr_result;
}

auto match_sequence (const vector<vector<int>>& A, const vector<int>& S)
{
    vector<vector<vector<bool>>> C(A.size(), vector<vector<bool>>(A[0].size(),
                                  vector<bool>(S.size(), false)));
    for (auto i = 0ul; i < A.size(); ++i) {
        for (auto j = 0ul; j < A[i].size(); ++j) {
            if (match_sequence_h(A,S,i,j,0,C)) {
                return true;
            }
        }
    }
    return false;
}

int main (void)
{
    vector<vector<int>> A{{1,2,3},{3,4,5},{5,6,7}};
    vector<int> S1{1,3,4,6};
    vector<int> S2{1,2,3,4};

    assert(match_sequence(A,S1) == true);
    assert(match_sequence(A,S2) == false);

    return 0;
}
