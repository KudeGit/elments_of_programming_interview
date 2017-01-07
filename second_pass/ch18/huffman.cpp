#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <string>

struct Symbol {
    char symbol;
    double prob;
    std::string  code;
};


struct HuffmanTreeNode {
    double prob;
    std::unique_ptr<Symbol> ptr_symbol = nullptr;
    std::shared_ptr<HuffmanTreeNode> left = nullptr;
    std::shared_ptr<HuffmanTreeNode> right = nullptr;
};

struct Compare {
    bool operator() (const std::shared_ptr<HuffmanTreeNode> lhs,
            const std::shared_ptr<HuffmanTreeNode> rhs) const
    {
        if (lhs != nullptr && rhs != nullptr) {
            return lhs->prob > rhs->prob;
        }
        return true;
    }
};

void assign_codes (std::shared_ptr<HuffmanTreeNode>& root, const std::string curr_code)
{
    if (!root) {
        return;
    }
    if (root->ptr_symbol) {
        root->ptr_symbol->code = curr_code;
    } else {
        assign_codes(root->left, curr_code + "0");
        assign_codes(root->right, curr_code + "1");
    }

}


std::shared_ptr<HuffmanTreeNode> encode (const std::vector<Symbol>& symbols)
{
    std::priority_queue<std::shared_ptr<HuffmanTreeNode>,
                        std::vector<std::shared_ptr<HuffmanTreeNode>>,
                        Compare> Q;
    if (symbols.empty()) {
        return nullptr;
    }

    for (auto& s: symbols) {
        Q.push(std::make_shared<HuffmanTreeNode>(HuffmanTreeNode{s.prob,
                    std::make_unique<Symbol>(s), nullptr, nullptr}));
    }
    if(Q.size() == 1) {
        //fake node to take care of this corner case
        Q.push(std::make_shared<HuffmanTreeNode>(HuffmanTreeNode{0,
                    nullptr, nullptr, nullptr}));
    }
    while (Q.size() > 1) {
        auto left = Q.top(); Q.pop();
        auto right = Q.top(); Q.pop();
        Q.push(std::make_shared<HuffmanTreeNode>(
                    HuffmanTreeNode{left->prob + right->prob,
                    nullptr,
                    left, right}));
    }
    auto root = Q.top(); Q.pop();
    assign_codes(root, "");
    return root;
}

void print_codes (const std::shared_ptr<HuffmanTreeNode>& root)
{
    if (!root) {
        return;
    }
    if (root->ptr_symbol != nullptr) {
        std::cout << root->ptr_symbol->symbol <<": " <<
            root->ptr_symbol->code << std::endl;
    }
    print_codes(root->left);
    print_codes(root->right);
}

int main (void)
{
    //std::vector<Symbol> = {
    //    {'a', 8.167},
    //    {'b',1.492},
    //    {'c', 2.782},
    //    {'d', 4.253},{ 12.702},{ 2.228},{ 2.015},{ 6.094},{ 6.966},{
    //    0.153},{ 0.772},{ 4.025},{ 2.406},{ 6.749},{  7.507},{ 1.929},{ 0.095},{ 5.987},{
    //        6.327},{ 9.056},{ 2.758},{ 0.978},{ 2.360},{  0.150},{ 1.974},{ 0.074}
    //
    //}
    std::vector<Symbol> symbols{{'a', 0.33, ""},
        {'b', 0.33, ""},
        {'c', 0.33, ""},
    };
    auto res = encode(symbols);
    print_codes(res);
    return 0;
}



