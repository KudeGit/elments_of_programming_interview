#include <iostream>
#include <vector>

bool parity(size_t a)
{
    int p = 0;
    while (a) {
        ++p;
        a &= (a-1);
    }
    return (p & 0x1) == 0;
}


int main (void)
{
    std::vector<int> test = {0, 1, 2, 3, 4, 5, 7, 63, 64};
    std::vector<bool> res = {true, false, false, true, false, true, false, true, true};
    int i = 0;
    bool p = false;
    for (auto a: test) {
        if( (p = parity(a)) != res[i]) {
            std::cout << "error with parity(" << a << ") returned " << p << " but expected " << res[i] << std::endl;
        }
        ++i;
    }
}
