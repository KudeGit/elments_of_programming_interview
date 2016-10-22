#include <iostream>
#include <string>


std::string get_snake_string (const std::string& str)
{
    std::string res(str.size(), 0);
    int i = 1;
    int j = 0;
    while (i < str.size()) {
        res[j++] = str[i];
        i += 4;
    }
    i = 0;
    while (i < str.size()) {
        res[j++] = str[i];
        i += 2;
    }
    i = 3;
    while (i < str.size()) {
        res[j++] = str[i];
        i += 4;
    }
    return res;
}


std::string get_snake_string (const char* c_str)
{
    std::string str(c_str);
    return get_snake_string(str);
}


int main (void)
{
    std::cout << get_snake_string("Hello World!") << std::endl;
}
