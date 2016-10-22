x





// https://www.topcoder.com/community/data-science/data-science-tutorials/using-tries/


#include <iostream>
#include <unordered_map>
#include <string>
#include "utils.hpp"

using namespace std;


/*
struct TrieNode {
    unordered_map<char, std::pair<int, TrieNode*>> children;
    bool is_end = false;
    string final_word("");
    char val;
    void insert (const std::string& str);
    void insertHelper (TrieNode* root, const std::string& str, const int cstart);
    bool isPrefix(const std::string& str);
    bool isPrefixHelper(TrieNode* root, const std::string& str, const int k);
};


bool TrieNode::isPrefixHelper (TrieNode* curr, const std::string& str, int k)
{
    if (curr) {
        //debug(curr->val);
        //debug(curr->children);
    }
    if(!curr) {
        //debug("curr is null");
        return false;
    } else if (k >= str.size()) {
        //debug("k is too large");
        return false;
    } else if (curr->val != str[k]) {
        //debug("char mismatch");
        return false;
    }else if (curr->is_end) {
        //debug("prefix found");
        return true;
    } else {
        TrieNode* child = nullptr;
        if (k < str.size() - 1 && curr->children.find(str[k+1]) != curr->children.end()) {
            child = curr->children[str[k+1]].second;
        }
        return isPrefixHelper(child, str, k+1);
    }
}

bool TrieNode::isPrefix (const std::string& str)
{
    if (str.empty()) {
        return true;
    }
    TrieNode* root = children.find(str[0]) == children.end() ? nullptr : children[str[0]].second;
    return isPrefixHelper(root, str, 0);

}



void TrieNode::insertHelper (TrieNode* root, const std::string& str, const int k)
{
    //ibanner();
    if (root->children.find(str[k]) == root->children.end()) {
        root->children[str[k]] = std::make_pair(1, TrieNode());
        root->children[str[k]].second->val = str[k];
    }
    ////debug(root->children);
    if (k >= str.size() - 1) {
        root->children[str[k]].second->is_end = true;
    } else {
        insertHelper(root->children[str[k]].second, str, k+1);
    }
    return;
}

void TrieNode::insert (const std::string& str)
{
    this->val = -1;
    for (int i = 0; i < str.size(); ++i) {
        insertHelper(this, str, i);
    }
    return;
}

void print_all_prefixes_helper (TrieNode* root, std::string& str)
{
    if (!root){
        return;
    }
    str.push_back(root->val);
    if (root->is_end) {
        cout << str << "." << endl;
    }
    for (auto& child: root->children) {
        print_all_prefixes_helper(child.second.second, str);
    }
    str.pop_back();
}

void print_all_prefixes (TrieNode* root) 
{
    std::string str;
    return print_all_prefixes_helper(root, str);
}
*/



struct TrieNode {
    char c = 0;
    int word_count = 0;
    bool words = false;
    int prefixes = 0;
    unordered_map<char, TrieNode*> children;
};


std::ostream& operator<< (std::ostream& out, TrieNode x)
{
    out << "(" << "c: " <<x.c << ", " <<
        "word_count: " << x.word_count << ", " <<
        "words: " << x.words << ", " <<
        "prefixes: " << x.prefixes << ")";

    return out;
}




void addWordHelper (const std::string& str, const int k, TrieNode* curr)
{
    if (k == str.size()) {
        curr->words = true;
        curr->word_count += 1;
        return;
    }
    if (curr->children.find(str[k]) == curr->children.end()) {
        curr->children[str[k]] = new TrieNode();
        curr->children[str[k]]->c = str[k];
    }
    ++curr->children[str[k]]->prefixes;
    addWordHelper(str, k+1, curr->children[str[k]]);

    return;
}


void print_trie (TrieNode* root)
{
    std::cout << *root << std::endl;
    for (auto& child_pair: root->children) {
        auto child = child_pair.second;
        print_trie(child);
    }
}


void addWord (TrieNode* root, const std::string& str)
{
    if (str.empty()) {
        root->words = true;
        ++root->word_count;
    } else {
        addWordHelper(str, 0, root);
    }
}

int countWordsHelper (TrieNode* root, const std::string& str, int k)
{
    if (k == str.size() ) {
        return root->word_count;
    } if (root->children.find(str[k]) == root->children.end()) {
        return 0;
    } else {
        return countWordsHelper(root->children[str[k]], str, k+1);
    }


    return 0;
}

int countWords (TrieNode *root, const std::string& str)
{
    if (str.empty()) {
        return root->word_count;
    } else {
        return countWordsHelper(root, str, 0);
    }
}



int countPrefixesHelper (TrieNode* root, const std::string& prefix, int k)
{
    if (k == prefix.size()) {
        return root->prefixes;
    } else {
        if (root->children.find(prefix[k]) == root->children.end()) {
            return 0;
        } else {
            return countPrefixesHelper(root->children[prefix[k]], prefix, k+1);
        }
    }
}

int countPrefixes (TrieNode* root, const std::string& prefix)
{
    if (prefix.empty()) {
        return root->prefixes;
    } else {
        return countPrefixesHelper(root, prefix, 0);
    }
}

string findShortestPrefixHelper (TrieNode* root, const std::string& str, int k)
{
    if (k == str.size()) {
        return root->words == true ? str : "";
    } else if (root->prefixes == 1) {
        return str.substr(0, k);
    } else {
        if (root->children.find(str[k]) ==  root->children.end()) {
            return "";
        } else {
            return findShortestPrefixHelper(root->children[str[k]], str, k+1);
        }
    }
}

string  findShortestPrefix (TrieNode* root, const std::string& str)
{
    if (str.empty()) {
        return "";
    } else {
        return findShortestPrefixHelper(root, str, 0);
    }
}

int main (void)
{
    std::string str("banana");
    TrieNode A;
    for (auto& word: {"zebra", "dog", "duck", "dove"}) {
        addWord(&A, word);
    }

    for (auto& word: {"zebra", "dog", "duck", "dove"}) {
        auto res = findShortestPrefix(&A, word);
        debug(res);
    }
    print_trie(&A);
    auto res = countWords(&A, str);
    cout << res << endl;
    res = countPrefixes(&A, "bana");
    debug(res);
    return 0;
}
