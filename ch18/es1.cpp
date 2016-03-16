#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>
#include "../utils.hpp"

struct huffman_symbol {
    char symbol = 0;
    double frequecy = 0.0;
};

using HS = huffman_symbol;

struct BTN
{
    HS* data = nullptr;
    std::shared_ptr<BTN> left = nullptr;
    std::shared_ptr<BTN> right = nullptr;
    //if we need a link to the parent, use weak_ptr to 
    //avoid cycle
};



struct comparator_hs
{
    bool operator() (const std::shared_ptr<BTN>& lhs,
            const std::shared_ptr<BTN>& rhs) {
        return lhs->data->frequecy > rhs->data->frequecy;
    }

};




std::shared_ptr<BTN> build_huffman_tree (std::vector<huffman_symbol>& symbols)
{
    std::shared_ptr<BTN> root = nullptr;
    std::priority_queue<std::shared_ptr<BTN>, std::vector<std::shared_ptr<BTN>>, comparator_hs> pq;
    for (auto& symbol: symbols) {
        auto ptr_btn = std::make_shared<BTN>();
        ptr_btn->data = &symbol;
        pq.push(ptr_btn);
    }
    while (pq.size() != 1) {
        auto left_btn = pq.top();
        pq.pop();
        if(pq.empty()) {
            throw std::logic_error("pq cannot be empty");
        }
        auto right_btn = pq.top();
        pq.pop();

        std::shared_ptr<BTN> current_root = std::make_shared<BTN>();
        current_root->left = left_btn;
        current_root->right = right_btn;
        current_root->data = new HS;
        current_root->data->symbol = 0;
        current_root->data->frequecy = left_btn->data->frequecy + right_btn->data->frequecy;
        pq.push(current_root);
    }
    root = pq.top(); pq.pop();
    debug(root->data->frequecy);
    return root;
}

void compute_encoding (std::shared_ptr<BTN> root, 
        std::unordered_map<char, std::string>& encoding, 
        std::string& current_encoding)
{
    if (!root->left && !root->right) {
        assert(root->data->symbol != 0);
        encoding[root->data->symbol] = current_encoding;
        return;
    }
    current_encoding.push_back('0');
    compute_encoding(root->left, encoding, current_encoding);
    current_encoding.pop_back();

    current_encoding.push_back('1');
    compute_encoding(root->right, encoding, current_encoding);
    current_encoding.pop_back();
}


int main (void)
{
    std::vector<HS> symbols;
    HS a, b, c, d, e;
    a.symbol='a';
    a.frequecy = 0.3;           //0.3

    b.symbol='b';
    b.frequecy = 0.1;           //0.4

    c.symbol='c';
    c.frequecy = 0.3;           //0.7

    d.symbol='d';
    d.frequecy = 0.15;          //0.85

    e.symbol='e';
    e.frequecy = 0.15;          //1.0


    symbols.push_back(a);
    symbols.push_back(b);
    symbols.push_back(c);
    symbols.push_back(d);
    symbols.push_back(e);

    auto root = build_huffman_tree(symbols);
    std::unordered_map<char, std::string> encoding;
    std::string current_encoding;
    compute_encoding(root, encoding, current_encoding);
    std::cout << encoding << std::endl;


    return 0;
}
