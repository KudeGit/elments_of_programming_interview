//step 1. Move n-1 disk from source to tmp peg using dest as helper
//step 2. Mode disk n to dest peg
//step 3. Move back n-1 to dest from tmp using source as aux
//


#include <iostream>
#include <stack>
#include <cassert>
#include <array>
#include <stdexcept>

void hanoi_tower (int n, std::array<std::stack<int>, 3>& pegs, int sx, int tmp, int dest)
{
    if (n == 0) {
        return;
    }

    //move n-1 to tmp peg
    hanoi_tower(n - 1, pegs, sx, dest, tmp);

    //move n-th disk to dest
    auto disk = pegs[sx].top();
    if (!pegs[dest].empty()) {
        if (pegs[dest].top() < pegs[sx].top()) {
            std::cout <<"attempting  moving disk " << disk << " from " << sx << " to " << dest << std::endl;
            throw std::logic_error("cannot push a larger disk on top of smaller one");
        }
    }
    if (pegs[sx].empty()) {
        throw std::logic_error("cannot pop from an empty stack");
    }
    std::cout <<"moving disk " << disk << " from " << sx << " to " << dest << std::endl;
    pegs[dest].push(disk);
    pegs[sx].pop();

    //move n-1 disk to dest from tmp using sx
    hanoi_tower(n - 1, pegs, tmp, sx, dest);

}


int main (void)
{
    std::array<std::stack<int>, 3> pegs;
    int n = 4;
    for (int i = n; i > 0; --i) {
        pegs[0].push(i);
    }
    hanoi_tower(n, pegs, 0, 1, 2);
    return 0;
}
