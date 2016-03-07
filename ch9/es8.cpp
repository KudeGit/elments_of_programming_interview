#include <iostream>
#include <stack>
#include <vector>



std::stack<int> compute_sunset_view (const std::vector<int>& buildings)
{
    std::stack<int> S;
    for (int i = 0; i < buildings.size(); ++i) {
        if(S.empty()) {
            S.push(i);
        } else {
            while (!S.empty() && buildings[S.top()] <= buildings[i]) {
                S.pop();
            }
            S.push(i);
        }
    }
    return S;
}



int main (void)
{
    std::vector<int> b = {3,2,7,3,2,6,5,4};
    auto res = compute_sunset_view(b);
    while(!res.empty()) {
        std::cout << res.top() << ", ";
        res.pop();
    }
    std::cout << std::endl;
    return 0;
}
