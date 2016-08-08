#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <tuple>
#include <functional>
#include <stdexcept>

struct RPN {
    int evaluate (const std::string& str);
    static std::unordered_map<std::string, std::function<int(int,int)>>  operations;
    int evaluate (const std::stack<std::string>& s);
    std::string get_next_token(const std::string& expr, int& curr);
    int check_and_pop(std::stack<int>& s);
};

std::unordered_map<std::string, std::function<int(int,int)>>  RPN::operations = {
    {"+", [](int x, int y) {return x+y;}},
    {"-", [](int x, int y) {return x-y;}},
    {"*", [](int x, int y) {return x*y;}},
    {"/", [](int x, int y) {return x/y;}},
};

std::string RPN::get_next_token(const std::string& expr, int& curr)
{
    std::stringstream ss;
    while (expr[curr] != ',' && curr < expr.size()) {
        ss << expr[curr++];
    }
    ++curr;
    return ss.str();

}

int RPN::check_and_pop(std::stack<int>& s)
{
    if(s.empty()) {
        throw std::length_error("stack is empty");
    }
    int a = s.top();
    s.pop();
    return a;
}

int RPN::evaluate (const std::string& expr)
{
    std::stack<int> s;
    int curr = 0;
    int res = 0;
    std::stringstream ss(expr);
    std::string token;
    while(getline(ss, token, ',')) {
        if(operations.find(token) == operations.end()) {
            s.push(std::stoi(token));
        } else {
            auto a = check_and_pop(s);
            auto b = check_and_pop(s);
            res = operations[token](a,b);
            s.push(res);
        }
    }
    return res;
}



int main (void)
{
    auto test = [](int x, int y) {return x+y;};
    std::cout << typeid(decltype(test)).name() << std::endl;
    RPN rpn;
    std::string expr1("3,4,*,1,-2,+,+");
    auto expr2 = {"1,1,+,-2,*"};
    auto a = rpn.evaluate(expr1);
    std::cout << a << std::endl;
    return 0;
}
