#include <iostream>
#include <string>
#include "../utils.hpp"

void transform_str(std::string& str)
{
    int deletion = 0;
    int addition = 0;
    int i, j;
    for (int i = 0, j = 0; i < str.size(); ++i) {
        if(!(str[i] == 'b')) {
            addition = str[i] == 'a' ? addition + 1 : addition;
            str[j++] = str[i];
        } else {
            ++deletion;
        }
    }
    int original_size = str.size() - deletion;
    str.resize(str.size() - deletion + addition);
    for (int i = original_size - 1, j = str.size() - 1; i >= 0; --i) {
        if(str[i] == 'a') {
            str[j--] = 'd';
            str[j--] = 'd';
        } else {
            str[j--] = str[i];
        }
    }

}


int main (void)
{
    std::string str("abcdabcde");
    transform_str(str);
    std::cout << str << std::endl;

    return 0;
}
