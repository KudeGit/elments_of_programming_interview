#include <memory>
#include "ch15.hpp"

///////////////////////////////////////////
std::unique_ptr<BSTNode<int>> build_fig1()
{
    std::unique_ptr<BSTNode<int>> A = std::make_unique<BSTNode<int>>(BSTNode<int>{19, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> B = std::make_unique<BSTNode<int>>(BSTNode<int>{7 , nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> C = std::make_unique<BSTNode<int>>(BSTNode<int>{3 , nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> D = std::make_unique<BSTNode<int>>(BSTNode<int>{2 , nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> E = std::make_unique<BSTNode<int>>(BSTNode<int>{5 , nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> F = std::make_unique<BSTNode<int>>(BSTNode<int>{11, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> G = std::make_unique<BSTNode<int>>(BSTNode<int>{17, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> H = std::make_unique<BSTNode<int>>(BSTNode<int>{13, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> I = std::make_unique<BSTNode<int>>(BSTNode<int>{43, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> J = std::make_unique<BSTNode<int>>(BSTNode<int>{23, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> K = std::make_unique<BSTNode<int>>(BSTNode<int>{37, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> L = std::make_unique<BSTNode<int>>(BSTNode<int>{29, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> M = std::make_unique<BSTNode<int>>(BSTNode<int>{31, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> N = std::make_unique<BSTNode<int>>(BSTNode<int>{41, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> O = std::make_unique<BSTNode<int>>(BSTNode<int>{47, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> P = std::make_unique<BSTNode<int>>(BSTNode<int>{53, nullptr, nullptr});

    C->left = std::move(D); C->right = std::move(E);
    G->left = std::move(H);
    F->right = std::move(G);
    B->left = std::move(C); B->right = std::move(F);


    L->right = std::move(M);
    K->left = std::move(L); K->right = std::move(N);
    J->right = std::move(K);
    O->right = std::move(P);
    I->left = std::move(J); I->right = std::move(O);

    A->left = std::move(B); A->right = std::move(I);

    return A;
}

std::unique_ptr<BSTNode<int>> build_fig2()
{
    std::unique_ptr<BSTNode<int>> A = std::make_unique<BSTNode<int>>(BSTNode<int>{108, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> B = std::make_unique<BSTNode<int>>(BSTNode<int>{108, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> C = std::make_unique<BSTNode<int>>(BSTNode<int>{-10, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> D = std::make_unique<BSTNode<int>>(BSTNode<int>{-14, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> E = std::make_unique<BSTNode<int>>(BSTNode<int>{2  , nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> F = std::make_unique<BSTNode<int>>(BSTNode<int>{108, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> G = std::make_unique<BSTNode<int>>(BSTNode<int>{285, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> H = std::make_unique<BSTNode<int>>(BSTNode<int>{243, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> I = std::make_unique<BSTNode<int>>(BSTNode<int>{285, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> J = std::make_unique<BSTNode<int>>(BSTNode<int>{401, nullptr, nullptr});

    C->left = std::move(D); C->right = std::move(E);
    B->left = std::move(C); B->right = std::move(F);


    I->left = std::move(J);
    G->left = std::move(H); G->right = std::move(I);

    A->left = std::move(B); A->right = std::move(G);

    return A;
}

std::unique_ptr<BSTNode<int>> build_simple_bst()
{
    std::unique_ptr<BSTNode<int>> A = std::make_unique<BSTNode<int>>(BSTNode<int>{2, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> B = std::make_unique<BSTNode<int>>(BSTNode<int>{1, nullptr, nullptr});
    std::unique_ptr<BSTNode<int>> C = std::make_unique<BSTNode<int>>(BSTNode<int>{3, nullptr, nullptr});
    A->left = std::move(B); A->right = std::move(C);
    return A;
}
