#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include "../utils.hpp"


struct State {
    std::string name;
    int votes;
};



long num_ways(const std::vector<State>& states)
{
    auto votes = std::accumulate(states.begin(), states.end(),
            0, [](int b, const State& s){return b + s.votes;});
    std::vector<std::vector<long long>> K(votes + 1,
            std::vector<long long>(states.size() + 1, 0));

    for (int i = 0; i <= states.size(); ++i) {
        K[0][i] = 1;
    }
    for (int i = 0; i < states.size(); ++i) {
        for (int v = 1; v <= votes; ++v) {
            K[v][i+1] = K[v][i] +
                (states[i].votes <= v ? K[v - states[i].votes][i] : 0);
            if(K[v][i+1] < 0) {
                debug(K[v][i+1]);
                debug(i);
                debug(v);
            }
        }
    }
    debug(K);

    debug(K.back().back());
    return K[votes >> 1].back();
}


int main (void)
{
    const std::vector<State> states = {
        State{"Alabama", 9}, State{"Montana", 3},
        State{"Alaska", 3}, State{"Nebraska", 5},
        State{"Arizona", 11}, State{"Nevada", 6},
        State{"Arkansas", 6}, State{"New Hampshire", 4},
        State{"California", 55}, State{"New Jersey", 14},
        State{"Colorado", 9}, State{"New Mexico", 5},
        State{"Connecticut", 7}, State{"New York", 29},
        State{"Delaware", 3}, State{"North Carolina", 15},
        State{"Florida", 29,}, State{"North Dakota", 3},
        State{"Georgia", 16}, State{"Ohio", 18},
        State{"Hawaii", 4}, State{"Oklahoma", 7},
        State{"Idaho", 4}, State{"Oregon", 7},
        State{"Illinois", 20}, State{"Pennsylvania", 20},
        State{"Indiana", 11}, State{"Rhode Island", 4},
        State{"Iowa", 6}, State{"South Carolina", 9},
        State{"Kansas", 6}, State{"South Dakota", 3},
        State{"Kentucky", 8}, State{"Tennessee", 11},
        State{"Louisiana", 8}, State{"Texas", 38},
        State{"Maine", 4}, State{"Utah", 6},
        State{"Maryland", 10}, State{"Vermont", 3},
        State{"Massachusetts", 11}, State{"Virginia", 13},
        State{"Michigan", 16}, State{"Washington", 12},
        State{"Minnesota", 10}, State{"West Virginia", 5},
        State{"Mississippi", 6}, State{"Wisconsin", 10},
        State{"Missouri", 10}, State{"Wyoming", 3},
        State{"Washington, D.C.", 3},
    };
    auto votes = num_ways(states);
    debug(votes);
    return 0;
}
