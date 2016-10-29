#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <regex>
#include <cmath>
#include "ch9.hpp"
#include "../../utils.hpp"


//std::unordered_map <std::string,std::function<int(int,int)>> operations = {
//    {"+", [](int a, int b) {return a+b;}    },
//    {"-", [](int a, int b) {return a-b;}    },
//    {"*", [](int a, int b) {return a*b;}    },
//    {"/", [](int a, int b) {return a/b;}    },
//
//};

enum class Associativity {LEFT, RIGHT};
enum class Precedence {LOW, MEDIUM, HIGH};


struct aritmetic_op {
    Associativity associativity;
    std::function<int(int, int)> operation;
    Precedence precedence;
};
bool operator< (const aritmetic_op& lhs, const aritmetic_op& rhs)
{
    return lhs.precedence < rhs.precedence;
}
bool operator> (const aritmetic_op& lhs, const aritmetic_op& rhs)
{
    return operator<(rhs, lhs);
}
bool operator<= (const aritmetic_op& lhs, const aritmetic_op& rhs)
{
    return !operator>(lhs,rhs);
}
bool operator>= (const aritmetic_op& lhs, const aritmetic_op& rhs)
{
    return !operator<=(lhs,rhs);
}
//other logical operator should not be need

std::unordered_map<std::string, aritmetic_op> operations = {
    {"+", {Associativity::LEFT, [](int a, int b) {return a+b;}, Precedence::LOW }},
    {"-", {Associativity::LEFT, [](int a, int b) {return a-b;}, Precedence::LOW }},
    {"*", {Associativity::LEFT, [](int a, int b) {return a*b;}, Precedence::MEDIUM}},
    {"/", {Associativity::LEFT, [](int a, int b) {return a/b;}, Precedence::MEDIUM}},
    {"^", {Associativity::RIGHT, [](int a, int b) {return std::pow(a,b);}, Precedence::HIGH}},
};


//assuming input is tokenized
std::string transform_to_rpn (const std::vector<std::string>& strs)
{
    //need a queue for the tokens and stack for the operands
    std::stringstream ss_out("");
    std::regex rpn_regex("(\\+|-)?[[:digit:]]+", std::regex::extended|std::regex::optimize);
    std::smatch sm;
    std::stack<std::string> ops_stack;
    for (const auto& str: strs) {
        std::regex_match(str.begin(), str.end(), sm, rpn_regex);

        if (sm.size()) {
            ss_out << str << ",";
        } else {
            auto it = operations.find(str);
            if (it == operations.end()) {
                //if it is not an operands... needs to be a parenthesis...
                if (str == "(" || str == "[" || str == "{") {
                    ops_stack.push(str);
                } else if (str == ")" || str == "]" || str == "}") {
                    while ((!ops_stack.empty()) &&
                            !(ops_stack.top() == "("
                            || ops_stack.top() == "[" ||
                            ops_stack.top() == "{")) {
                        //pop until first left parenthesis and put to the output buffer
                        ss_out << ops_stack.top() << ",";
                        ops_stack.pop();
                    }
                    if ( (str == ")" && ops_stack.top() != "(") ||
                         (str == "]"  && ops_stack.top() != "[") ||
                         (str == "}" && ops_stack.top() != "{")) {
                        throw std::invalid_argument("invalid parenthesis");
                    } else {
                        //pop the left parenthesis
                        ops_stack.pop();
                    }
                } else {
                    throw std::invalid_argument("invalid characther or operator");
                }
            } else {
                //ok it is a valid operator... let's work on the stack...
                if (ops_stack.empty() ||
                        (ops_stack.top() == "(")||
                        (ops_stack.top() == "[")||
                        (ops_stack.top() == "{")) {
                    ops_stack.push(str);
                } else {
                    auto& top_op = operations[ops_stack.top()];
                    auto& curr_op = operations[str];
                    while ((top_op.associativity == Associativity::LEFT && curr_op <= top_op) ||
                            (top_op.associativity == Associativity::RIGHT && curr_op < top_op)) {
                        ss_out << ops_stack.top() << ",";
                        ops_stack.pop();
                        if (ops_stack.empty()) {
                            break;
                        } else {
                            top_op = operations[ops_stack.top()];
                        }
                    }
                    ops_stack.push(str);
                }
            }
        }
    }
    while (!ops_stack.empty()) {
        // I can have only operands
        auto it = operations.find(ops_stack.top());
        if (it == operations.end()) {
            throw std::invalid_argument("Invalid string... prbably parenthesis unbalanced");
        }
        ss_out << ops_stack.top() << ",";
        ops_stack.pop();
    }
    auto out_str = ss_out.str();
    if (out_str.back() == ',') {
        out_str.pop_back();
    }
    return out_str;
}

int evalute_rpn (const std::string& str)
{
    std::stringstream ss(str);
    std::string token;
    std::stack<int> S;
    while (getline(ss, token, ',')) {
        auto it = operations.find(token);
        if (it != operations.end()) {
            if (S.empty()) {
                throw std::logic_error("Stack values is empty");
            }
            auto b = S.top(); S.pop();
            if (S.empty()) {
                throw std::logic_error("Stack values is empty");
            }
            auto a = S.top(); S.pop();
            auto c = it->second.operation(a, b);
            S.push(c);
        } else {
            S.push(stoi(token));
        }
    }
    return S.top();
}
